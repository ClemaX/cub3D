/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:19:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 01:18:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <tick.h>
#include <hooks.h>
#include <stdlib.h>

int		destroy_hook(t_env *env)
{
	env_destroy(env);
	exit(0);
}

int		focus_in_hook(t_env *env)
{
	mlx_mouse_hide();
	if (!env->focus)
		env->focus = 1;
	return (0);
}

int		focus_out_hook(t_env *env)
{
	mlx_mouse_show();
	env->focus = 0;
	return (0);
}

void	hooks_init(t_env *env, t_mode mode)
{
	mlx_loop_hook(env->mlx, (mode == INTERACT) ? &loop_hook : &benchmark, env);
	mlx_hook(env->win, DESTROY_NOTIFY, NO_EVENT_M, &destroy_hook, env);
	mlx_hook(env->win, KEY_PRESS, KEY_PRESS_M, &key_enable, env);
	mlx_hook(env->win, KEY_RELEASE, KEY_RELEASE_M, &key_disable, env);
	mlx_hook(env->win, FOCUS_IN, FOCUS_CHANGE_M, &focus_in_hook, env);
	mlx_hook(env->win, FOCUS_OUT, FOCUS_CHANGE_M, &focus_out_hook, env);
}