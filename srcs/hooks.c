/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:19:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 00:08:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>
#include <environment.h>
#include <stdlib.h>
#include <libftprintf.h>
#include <math.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	key_hook(int key, t_env *env)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		destroy_env(env);
		exit(0);
	}
	else if (key == UP)
	{
		env->map.player.pos.x += env->map.player.dir.x * 0.25;
		env->map.player.pos.y += env->map.player.dir.y * 0.25;
	}
	else if (key == DOWN)
	{
		env->map.player.pos.x -= env->map.player.dir.x * 0.25;
		env->map.player.pos.y -= env->map.player.dir.y * 0.25;
	}
	else if (key == LEFT)
	{
		vrotate(&env->map.player.dir, -0.1);
		vrotate(&env->map.player.plane, -0.1);
	}
	else if (key == RIGHT)
	{
		vrotate(&env->map.player.dir, 0.1);
		vrotate(&env->map.player.plane, 0.1);
	}
	else
		return (0);
	refresh(env);
	return (0);
}

int	destroy_hook(t_env *env)
{
	destroy_env(env);
	exit(0);
}
