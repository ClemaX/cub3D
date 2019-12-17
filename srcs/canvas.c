/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:45:57 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>

int						init_canvas(t_env *env)
{
	env->canvas.img = mlx_new_image(env->mlx,
		env->settings.width, env->settings.height);
	if (!env->canvas.img)
		return (0);
	env->canvas.data = mlx_get_data_addr(env->canvas.img,
		&env->canvas.bpp, &env->canvas.ls, &env->canvas.e);
	env->canvas.width = env->settings.width;
	env->canvas.height = env->settings.height;
	return (1);
}

static inline void		put_canvas(t_env *env, int x, int y, t_color color)
{
	((t_color*)env->canvas.data)[y * env->canvas.width + x] = color;
}

static inline t_color	get_color(t_image img, int x, int y)
{
	return (((t_color*)img.data)[y * img.width + x]);
}

void					draw_column(t_env *env, int x, t_obstacle obs)
{
	int	height;
	int	start;
	int	end;
	int	y;
	int index_y;

	height = env->settings.height / obs.distance;
	start = -height / 2 + env->settings.height / 2;
	end = height / 2 + env->settings.height / 2;
	if (start < 0)
		start = 0;
	if (end >= env->settings.height)
		end = env->settings.height - 1;
	y = 0;
	while (y < env->settings.height && y < start)
		put_canvas(env, x, y++, env->settings.color_f);
	while (y < end)
	{
		index_y = (((y * 256 - env->settings.height * 128 + height * 128) * env->tex[obs.face].height) / height) / 256;
		put_canvas(env, x, y++, get_color(env->tex[obs.face], obs.offset, index_y));
	}
	while (y < env->settings.height - 1)
		put_canvas(env, x, y++, env->settings.color_c);
}
