/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:31:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 23:08:03 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <ray.h>

static int collision(t_map *map, float x, float y)
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

void	move_player(t_env *env, t_vector movement)
{
	t_vector	new_pos;

	new_pos.x = env->player.x + movement.x;
	new_pos.y = env->player.y + movement.y;
	if (!collision(&env->map, new_pos.x, env->player.y))
		env->player.x = new_pos.x;
	if (!collision(&env->map, env->player.x, new_pos.y))
		env->player.y = new_pos.y;
}

t_vector	camera_transform(t_env *env, t_vector vector)
{
	const double	factor = 1.0 / (env->player.plane.x * FOV * env->player.dir.y
		- env->player.dir.x * env->player.plane.y * FOV);
	t_vector		transform;

	transform.x = factor * (env->player.dir.y * vector.x - env->player.dir.x * vector.y);
	transform.y = factor * (-env->player.plane.y * FOV * vector.x + env->player.plane.x * FOV * vector.y);
	return (transform);
}