/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 23:53:03 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>

int						init_canvas(t_env *env)
{
	env->canvas.ptr = mlx_new_image(env->mlx, env->settings.w, env->settings.h);
	if (!env->canvas.ptr)
		return (0);
	env->canvas.data = mlx_get_data_addr(env->canvas.ptr,
		&env->canvas.bpp, &env->canvas.ls, &env->canvas.e);
	env->canvas.w = env->settings.w;
	env->canvas.h = env->settings.h;
	env->zbuffer = malloc(sizeof(*env->zbuffer) * env->canvas.w);
	if (!env->zbuffer)
		return (0);
	return (1);
}

static inline void		put_canvas(t_env *env, int x, int y, t_color color)
{
	((t_color*)env->canvas.data)[y * env->canvas.w + x] = color;
}

static inline t_color	get_color(t_image img, int x, int y)
{
	return (((t_color*)img.data)[y * img.w + x]);
}

void					draw_column(t_env *env, int x)
{
	const t_obstacle	obs = env->zbuffer[x];
	const int			height = env->settings.h / obs.distance;
	int					start;
	int					end;
	int					y;

	start = -height / 2 + env->settings.h / 2;
	end = height / 2 + env->settings.h / 2;
	if (start < 0)
		start = 0;
	if (end >= env->settings.h)
		end = env->settings.h - 1;
	y = 0;
	while (y < env->settings.h && y < start)
		put_canvas(env, x, y++, env->settings.color_c);
	while (y < end)
	{
		put_canvas(env, x, y, get_color(env->tex[obs.face], obs.offset, 
		(((y * 256 - env->settings.h * 128 + height * 128) * env->tex[obs.face].h) / height) / 256));
		y++;
	}
	while (y < env->settings.h - 1)
		put_canvas(env, x, y++, env->settings.color_f);
}
