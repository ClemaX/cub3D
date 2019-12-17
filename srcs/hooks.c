/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:19:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 20:17:37 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <math.h>

int	mouse_hook(int button, int x, int y, t_env *env)
{
	(void)button;
	(void)x;
	(void)y;
	(void)env;
	return (0);
}

#include <tick.h>

int	loop_hook(t_env *env)
{
	static t_tick	tick;

	if (env->player.input == 0)
		return (0);
	start_tick(&tick);
	if (env->player.input & UP)
		move_player(env, env->player.dir, tick.delta * S_MOVEMENT);
	if (env->player.input & DOWN)
		move_player(env, env->player.dir, tick.delta * -S_MOVEMENT);
	if (env->player.input & LEFT)
	{
		move_player(env, env->player.plane, tick.delta * -S_MOVEMENT);
	}
	if (env->player.input & RIGHT)
	{
		move_player(env, env->player.plane, tick.delta * S_MOVEMENT);
	}
	if (env->player.input & ROT_LEFT && !(env->player.input & ROT_RIGHT))
	{
		vrotate(&env->player.dir, tick.delta * -S_ROTATION);
		vrotate(&env->player.plane, tick.delta * -S_ROTATION);
	}
	if (env->player.input & ROT_RIGHT && !(env->player.input & ROT_LEFT))
	{
		vrotate(&env->player.dir, tick.delta * S_ROTATION);
		vrotate(&env->player.plane, tick.delta * S_ROTATION);
	}
	refresh(env);
	end_tick(&tick);
	return (1);
}

int	key_enable(int key, t_env *env)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		destroy_env(env);
		exit(0);
	}
	if (key == KEY_UP)
		env->player.input ^= UP;
	if (key == KEY_DOWN)
		env->player.input ^= DOWN;
	if (key == KEY_LEFT)
		env->player.input ^= LEFT;
	if (key == KEY_RIGHT)
		env->player.input ^= RIGHT;
	if (key == KEY_ROT_L)
		env->player.input ^= ROT_LEFT;
	if (key == KEY_ROT_R)
		env->player.input ^= ROT_RIGHT;
	return (0);
}

int	key_disable(int key, t_env *env)
{
	if (key == KEY_UP)
		env->player.input &= ~UP;
	if (key == KEY_DOWN)
		env->player.input &= ~DOWN;
	if (key == KEY_LEFT)
		env->player.input &= ~LEFT;
	if (key == KEY_RIGHT)
		env->player.input &= ~RIGHT;
	if (key == KEY_ROT_L)
		env->player.input &= ~ROT_LEFT;
	if (key == KEY_ROT_R)
		env->player.input &= ~ROT_RIGHT;
	return (0);
}

int	destroy_hook(t_env *env)
{
	destroy_env(env);
	exit(0);
}
