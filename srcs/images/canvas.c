/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   canvas.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:04:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 01:08:08 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <canvas.h>
#include <stdlib.h>

static inline void		put_canvas(t_env *env, int x, int y, t_color color)
{
	*(t_color*)(env->canvas.data + (y * env->canvas.ls + x * (env->canvas.bpp / 8))) = color;
}

static inline t_color	get_color(t_image *img, int x, int y)
{
	return *(t_color*)(img->data + (y * img->ls + x * (img->bpp / 8)));
}

void					draw_stripe(t_env *env, t_stripe *stripe, t_image *tex)
{
	t_color	c;

	while (stripe->draw.y < stripe->end.y)
	{
		stripe->tex.y = (((stripe->draw.y * 256 - env->canvas.h * 128 +
			stripe->size * 128) * tex->h) / stripe->size) / 256;
		if (stripe->tex.y < 0)
			stripe->tex.y = 0;
		else if (stripe->tex.y >= tex->h)
			stripe->tex.y = tex->h - 1;
		c = get_color(tex, stripe->tex.x, stripe->tex.y);
		if (c.c)
			put_canvas(env, stripe->draw.x, stripe->draw.y, c);
		stripe->draw.y++;
	}
}

int					init_canvas(t_env *env)
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

void				draw_tex(t_env *env, int pos_x, float z, int size)
{
	t_stripe	stripe;
	t_ivector	start;

	stripe.size = size;
	start = ivector(pos_x - size / 2, (env->canvas.h - size) / 2);
	stripe.end = ivector(pos_x + size / 2, (env->canvas.h + size) / 2);
	stripe.draw.x = ((start.x < 0) ? 0 : start.x) - 1;
	if (stripe.end.x >= env->canvas.w)
		stripe.end.x = env->canvas.w - 1;
	if (stripe.end.y >= env->canvas.h)
		stripe.end.y = env->canvas.h - 1;
	while (stripe.draw.x++ < stripe.end.x)
	{
		if (z < env->zbuffer[stripe.draw.x])
		{
			stripe.tex.x = (256 * ((stripe.draw.x - start.x)
				* env->tex[SPRITE_TEX].w / size) / 256);
			if (stripe.tex.x < 0)
				stripe.tex.x = 0;
			else if (stripe.tex.x >= env->tex[SPRITE_TEX].w)
				stripe.tex.x = env->tex[SPRITE_TEX].w - 1;
			stripe.draw.y = (start.y < 0) ? 0 : start.y;
			draw_stripe(env, &stripe, &env->tex[SPRITE_TEX]);
		}
	}
}

void				draw_column(t_env *env, int x, t_obstacle obs)
{
	t_stripe	stripe;

	stripe.draw.x = x;
	stripe.tex.x = obs.offset;
	stripe.size = env->canvas.h / obs.distance;
	stripe.end.y = -stripe.size / 2 + env->canvas.h / 2;
	if (stripe.end.y < 0)
		stripe.end.y = 0;
	stripe.draw.y = 0;
	while (stripe.draw.y < env->canvas.h && stripe.draw.y < stripe.end.y)
		put_canvas(env, stripe.draw.x, stripe.draw.y++, env->settings.color_c);
	stripe.end.y += stripe.size;
	if (stripe.end.y >= env->canvas.h)
		stripe.end.y = env->canvas.h - 1;
	if (obs.offset < 0)
		obs.offset = 0;
	else if (obs.offset >= env->tex[obs.face].w)
		obs.offset = env->tex[obs.face].w - 1;
	draw_stripe(env, &stripe, &env->tex[obs.face]);
	while (stripe.draw.y < env->canvas.h - 1)
		put_canvas(env, stripe.draw.x, stripe.draw.y++, env->settings.color_f);
}
