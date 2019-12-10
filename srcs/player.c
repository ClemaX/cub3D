/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:31:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 17:23:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>

void	move_player(t_env *env, t_vector movement, double factor)
{
	if (env->map.cells[(env->map.size_x * (int)env->player.pos.y) + (int)(env->player.pos.x + movement.x * factor)].type != WALL)
		env->player.pos.x += movement.x * factor;
	if (env->map.cells[(env->map.size_x * (int)(env->player.pos.y + movement.y * factor)) + (int)env->player.pos.x].type != WALL)
		env->player.pos.y += movement.y * factor;
}
