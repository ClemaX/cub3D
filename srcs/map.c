/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:31:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:29:01 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <ray.h>

static int	collision(t_map *map, float x, float y)
{
	static const float	half_hitbox = HITBOX / 2;
	t_vector			check[4];
	int					i;

	check[0].x = x + half_hitbox;
	check[0].y = y + half_hitbox;
	check[1].x = x - half_hitbox;
	check[1].y = y - half_hitbox;
	check[2].x = x + half_hitbox;
	check[2].y = y - half_hitbox;
	check[3].x = x - half_hitbox;
	check[3].y = y + half_hitbox;
	i = 0;
	while (i < 4
	&& map->cells[(int)check[i].y * map->w + (int)check[i].x] == SPACE)
		i++;
	return (i != 4);
}

void		move_player(t_map *map, t_vector *movement)
{
	t_vector	new_pos;

	new_pos.x = map->player.x + movement->x;
	new_pos.y = map->player.y + movement->y;
	if (!collision(map, new_pos.x, map->player.y))
		map->player.x = new_pos.x;
	if (!collision(map, map->player.x, new_pos.y))
		map->player.y = new_pos.y;
}

t_vector	camera_transform(t_player *player, t_vector vector)
{
	double		factor;
	t_vector	transform;

	factor = 1.0 / (player->plane.x * FOV * player->dir.y
		- player->dir.x * player->plane.y * FOV);
	transform.x = factor *
		(player->dir.y * vector.x - player->dir.x * vector.y);
	transform.y = factor *
		(-player->plane.y * FOV * vector.x + player->plane.x * FOV * vector.y);
	return (transform);
}
