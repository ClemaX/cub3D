/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:19:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 05:09:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <tick.h>
#include <vmath.h>
#include <limits.h>

int	loop_hook(t_env *env)
{
	const int	half_w = env->canvas.w / 2;
	const int	half_h = env->canvas.h / 2;
	t_ivector	mouse;
	float		delta;

	if (!env->focus)
		return (0);
	mlx_mouse_get_pos(env->win, &mouse.x, &mouse.y);
	mlx_mouse_move(env->win, half_w, half_h);
	delta = (mouse.x - half_w) / (float)(MOUSE_SENS);
	vrotate(&env->map.player.dir, delta);
	vrotate(&env->map.player.plane, delta);
	if (!(delta || env->input))
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
		env->input ^= UP;
	else if (key == KEY_DOWN)
		env->input ^= DOWN;
	else if (key == KEY_LEFT)
		env->input ^= LEFT;
	else if (key == KEY_RIGHT)
		env->input ^= RIGHT;
	else if (key == KEY_ROT_L)
		env->input ^= ROT_LEFT;
	else if (key == KEY_ROT_R)
		env->input ^= ROT_RIGHT;
	else
		return (0);
	return (1);
}

int	key_disable(int key, t_env *env)
{
	if (key == KEY_UP)
		env->input &= ~UP;
	else if (key == KEY_DOWN)
		env->input &= ~DOWN;
	else if (key == KEY_LEFT)
		env->input &= ~LEFT;
	else if (key == KEY_RIGHT)
		env->input &= ~RIGHT;
	else if (key == KEY_ROT_L)
		env->input &= ~ROT_LEFT;
	else if (key == KEY_ROT_R)
		env->input &= ~ROT_RIGHT;
	else
		return (0);
	return (1);
}

int	destroy_hook(t_env *env)
{
	destroy_env(env);
	exit(0);
}

int	focus_in_hook(t_env *env)
{
	mlx_mouse_hide();
	if (!env->focus)
		env->focus = 1;
	return (0);
}

int	focus_out_hook(t_env *env)
{
	mlx_mouse_show();
	env->focus = 0;
	return (0);
}