/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:31:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 22:41:18 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>

void	move_player(t_env *env, double factor)
{
	if (env->map.cells[(env->map.size_x * (int)env->player.pos.y) + (int)(env->player.pos.x + env->player.dir.x * factor)].type != WALL)
		env->player.pos.x += env->player.dir.x * factor;
	if (env->map.cells[(env->map.size_x * (int)(env->player.pos.y + env->player.dir.y * factor)) + (int)env->player.pos.x].type != WALL)
	env->player.pos.y += env->player.dir.y * factor;
}
