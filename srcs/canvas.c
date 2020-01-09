/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 05:44:02 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>

static inline void		put_canvas(t_env *env, int x, int y, t_color color)
{
	((t_color*)env->canvas.data)[y * env->canvas.w + x] = color;
}

static inline t_color	get_color(t_image img, int x, int y)
{
	return (((t_color*)img.data)[y * img.w + x]);
}

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

void					draw_tex(t_env *env, int pos_x, int z, int size)
{
	int 		x;
	int			y;
	t_ivector	start;
	t_ivector	end;
	t_ivector	tex;

	start = ivector(pos_x - size / 2, (env->settings.h - size) / 2);
	end = ivector(pos_x + size / 2, (env->settings.h + size) / 2);
	x = (start.x < 0) ? 0 : start.x;
	if (end.x >= env->settings.w)
		end.x = env->settings.w - 1;
	if (end.y >= env->settings.h)
		end.y = env->settings.h - 1;
	while (x < end.x)
	{
		if (z < env->zbuffer[x])
		{
			tex.x = (256 * ((x - start.x) * env->tex[SPRITE_TEX].w / size) / 256);
			y = (start.y < 0) ? 0 : start.y;
			while (y < end.y)
			{
				tex.y = (((y * 256 - env->settings.h * 128 + size * 128) * env->tex[SPRITE_TEX].h) / size) / 256;
				t_color c = get_color(env->tex[SPRITE_TEX], tex.x, tex.y);
				if (c.c)
					put_canvas(env, x, y, c);
				y++;
			}
		}
		x++;
	}
}

void					draw_column(t_env *env, int x, t_obstacle obs)
{
	const int	height = env->settings.h / obs.distance;
	int	start;
	int	end;
	int	y;
	int tex_y;

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
		tex_y = (((y * 256 - env->settings.h * 128 + height * 128) * env->tex[obs.face].h) / height) / 256;
		put_canvas(env, x, y++, get_color(env->tex[obs.face], obs.offset, tex_y));
	}
	while (y < env->settings.h - 1)
		put_canvas(env, x, y++, env->settings.color_f);
}

/* void					draw_column(t_env *env, int x)
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
} */
