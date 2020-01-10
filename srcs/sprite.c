/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 01:25:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 05:13:27 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <libft.h>
#include <map.h>
#include <math.h>
#include <sprite.h>
#include <stdlib.h>
#include <canvas.h>

t_list	*new_sprite(int x, int y, t_sprite_id id)
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

void		draw_sprite(t_env *env, t_sprite *sprite)
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
