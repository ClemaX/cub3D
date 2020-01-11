/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:35:22 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:18:21 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sprite.h>
#include <vmath.h>
#include <math.h>

void	sprites_dist(t_player *player, t_list *sprites)
{
	t_list		*current;
	t_sprite	*sprite;

	current = sprites;
	while (current)
	{
		sprite = (t_sprite*)current->content;
		sprite->rel.x = sprite->pos.x - player->x;
		sprite->rel.y = sprite->pos.y - player->y;
		sprite->dist = powf(sprite->rel.x, 2) + powf(sprite->rel.y, 2);
		current = current->next;
	}
}

int		sprite_cmp(void *a, void *b)
{
	const float	diff = ((t_sprite*)a)->dist - ((t_sprite*)b)->dist;

	return ((diff > 0) - (diff < 0));
}
