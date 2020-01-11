/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:09:33 by chamada     ###    #+. /#+    ###.fr     */
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
	t_ivector	draw;
	t_ivector	start;
	t_ivector	end;
	t_ivector	tex;
	t_color		c;

	start = ivector(pos_x - size / 2, (env->canvas.h - size) / 2);
	end = ivector(pos_x + size / 2, (env->canvas.h + size) / 2);
	draw.x = (start.x < 0) ? 0 : start.x;
	if (end.x >= env->canvas.w)
		end.x = env->canvas.w - 1;
	if (end.y >= env->canvas.h)
		end.y = env->canvas.h - 1;
	while (draw.x < end.x)
	{
		if (z < env->zbuffer[draw.x])
		{
			tex.x = (256 * ((draw.x - start.x) * env->tex[SPRITE_TEX].w / size) / 256);
			if (tex.x < 0)
				tex.x = 0;
			else if (tex.x >= env->tex[SPRITE_TEX].w)
				tex.x = env->tex[SPRITE_TEX].w - 1;
			draw.y = (start.y < 0) ? 0 : start.y;
			while (draw.y < end.y)
			{
				tex.y = (((draw.y * 256 - env->canvas.h * 128 + size * 128) * env->tex[SPRITE_TEX].h) / size) / 256;
				if (tex.y < 0)
					tex.y = 0;
				else if (tex.y >= env->tex[SPRITE_TEX].h)
					tex.y = env->tex[SPRITE_TEX].h - 1;
				c = get_color(env->tex[SPRITE_TEX], tex.x, tex.y);
				if (c.c)
					put_canvas(env, draw.x, draw.y, c);
				draw.y++;
			}
		}
		draw.x++;
	}
}

void					draw_column(t_env *env, int x, t_obstacle obs)
{
	const int	height = env->canvas.h / obs.distance;
	int			end;
	int			y;
	int			tex_y;

	end = -height / 2 + env->canvas.h / 2;
	if (end < 0)
		end = 0;
	y = 0;
	while (y < env->canvas.h && y < end)
		put_canvas(env, x, y++, env->settings.color_c);
	end += height;
	if (end >= env->canvas.h)
		end = env->canvas.h - 1;
	if (obs.offset < 0)
		obs.offset = 0;
	else if (obs.offset >= env->tex[obs.face].w)
		obs.offset = env->tex[obs.face].w - 1;
	while (y < end)
	{
		tex_y = (((y * 256 - env->canvas.h * 128 + height * 128)
			* env->tex[obs.face].h) / height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= env->tex[obs.face].h)
			tex_y = env->tex[obs.face].h - 1;
		put_canvas(env, x, y++, get_color(env->tex[obs.face], obs.offset, tex_y));
	}
	while (y < env->canvas.h - 1)
		put_canvas(env, x, y++, env->settings.color_f);
}
