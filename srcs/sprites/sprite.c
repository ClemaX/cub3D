/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 01:25:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:25:54 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <libft.h>
#include <map.h>
#include <math.h>
#include <sprite.h>
#include <stdlib.h>

t_list		*new_sprite(int x, int y, t_sprite_id id)
{
	t_list		*sprite;
	t_sprite	*content;

	if (!(content = malloc(sizeof(*content))))
		return (NULL);
	content->pos.y = y + .5;
	content->pos.x = x + .5;
	content->id = id;
	if (!(sprite = ft_lstnew(content)))
		free(content);
	return (sprite);
}

static void	draw_tex(t_env *env, int pos_x, float z, int size)
{
	t_ivector	start;
	t_stripe	stripe;

	stripe.size = size;
	start = (t_ivector){.x=pos_x - size / 2, .y=(env->canvas.h - size) / 2};
	stripe = (t_stripe){.size=size, .draw.x=((start.x < 0) ? 0 : start.x) - 1,
		.end.x=pos_x + size / 2, .end.y=(env->canvas.h + size) / 2};
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

static void	draw_sprite(t_env *env, t_sprite *sprite)
{
	const t_vector	transform = camera_transform(&env->map.player, sprite->rel);
	const int		x = (env->canvas.w / 2) * (1 + transform.x / transform.y);
	int				size;

	if (transform.y > 0)
	{
		size = abs((int)(env->canvas.h / transform.y));
		draw_tex(env, x, transform.y, size);
	}
}

void		draw_sprites(t_env *env)
{
	t_list	*current;

	if (!env->map.sprites)
		return ;
	sprites_dist(&env->map.player, env->map.sprites);
	ft_lstsort(&env->map.sprites, &sprite_cmp);
	current = env->map.sprites;
	while (current)
	{
		draw_sprite(env, current->content);
		current = current->next;
	}
}
