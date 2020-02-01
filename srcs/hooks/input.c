/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 00:36:27 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 02:25:15 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>

static void	mouse_toggle(t_env *env)
{
	if (env->focus == FOREGROUND)
	{
		mlx_mouse_hide();
		env->focus = MOUSE;
	}
	else if (env->focus == MOUSE)
	{
		mlx_mouse_show();
		env->focus = FOREGROUND;
	}
}

int			key_enable(int key, t_env *env)
{
	if (env->focus == BACKGROUND)
		return (0);
	if (key == KEY_ESCAPE)
	{
		env_destroy(env);
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
	else if (key == KEY_MOUSE)
		mouse_toggle(env);
	else
		return (0);
	return (1);
}

int			key_disable(int key, t_env *env)
{
	if (env->focus == BACKGROUND)
		return (0);
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
