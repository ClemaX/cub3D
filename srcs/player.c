/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:31:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:06:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <ray.h>

void	move_player(t_env *env, t_vector movement, float factor)
{
	static const float	half_hitbox = HITBOX / 2;
	t_vector			check[5];
	int					i;

	check[0].x = env->player.pos.x + movement.x * factor;
	check[0].y = env->player.pos.y + movement.y * factor;
	check[1].x = check[0].x + half_hitbox;
	check[1].y = check[0].y + half_hitbox;
	check[2].x = check[0].x - half_hitbox;
	check[2].y = check[0].y - half_hitbox;
	check[3].x = check[0].x + half_hitbox;
	check[3].y = check[0].y - half_hitbox;
	check[4].x = check[0].x - half_hitbox;
	check[4].y = check[0].y + half_hitbox;
	i = 0;
	while (i < 5 && env->map.cells[(int)check[i].y * env->map.size_x + (int)check[i].x].type != WALL)
		i++;
	if (i == 5)
		env->player.pos = check[0];
}
