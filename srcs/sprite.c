/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 01:25:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 00:20:42 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <libft.h>
#include <map.h>
#include <math.h>
#include <sprite.h>
#include <stdlib.h>

t_list	*new_sprite(int x, int y, t_sprite_id id)
{
	t_list		*sprite;
	t_sprite	*content;

	if (!(content = malloc(sizeof(*content))))
		return (NULL);
	content->pos.y = y;
	content->pos.x = x;
	content->id = id;
	if (!(sprite = ft_lstnew(content)))
		free(content);
	return (sprite);
}

void		draw_sprite(t_env *env, t_sprite *sprite)
{
	const t_vector	transform = camera_transform(env, sprite->pos);
	const int		x = (int)(env->settings.w / 2) * (1 + transform.x / transform.y);
	
	if (x < 0 || x >= env->settings.w || transform.y > env->zbuffer[x].distance)
		return ;
	
}

#include <stdio.h>

void		draw_sprites(t_env *env)
{
	if (!env->sprites)
		return ;
	sprites_dist(env, env->sprites);
	ft_lstcmpsort(&env->sprites, &sprite_cmp);
	dprintf(1, "\r");
	ft_lstiter(env->sprites, &print_sprite);
}
