/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:19:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 21:58:44 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <tick.h>

int	mouse_hook(int button, int x, int y, t_env *env)
{
	(void)button;
	(void)x;
	(void)y;
	(void)env;
	return (0);
}

int	loop_hook(t_env *env)
{
	if (env->player.input == 0)
		return (0);
	do_tick(env);
	return (1);
}

int	key_enable(int key, t_env *env)
{
	if (key == KEY_ESCAPE)
	{
		destroy_env(env);
		exit(0);
	}
	else if (key == KEY_UP)
		env->player.input ^= UP;
	else if (key == KEY_DOWN)
		env->player.input ^= DOWN;
	else if (key == KEY_LEFT)
		env->player.input ^= LEFT;
	else if (key == KEY_RIGHT)
		env->player.input ^= RIGHT;
	else if (key == KEY_ROT_L)
		env->player.input ^= ROT_LEFT;
	else if (key == KEY_ROT_R)
		env->player.input ^= ROT_RIGHT;
	else
		return (0);
	return (1);
}

int	key_disable(int key, t_env *env)
{
	if (key == KEY_UP)
		env->player.input &= ~UP;
	else if (key == KEY_DOWN)
		env->player.input &= ~DOWN;
	else if (key == KEY_LEFT)
		env->player.input &= ~LEFT;
	else if (key == KEY_RIGHT)
		env->player.input &= ~RIGHT;
	else if (key == KEY_ROT_L)
		env->player.input &= ~ROT_LEFT;
	else if (key == KEY_ROT_R)
		env->player.input &= ~ROT_RIGHT;
	else
		return (0);
	return (1);
}

int	destroy_hook(t_env *env)
{
	destroy_env(env);
	exit(0);
}
