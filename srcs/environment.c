/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 08:48:22 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <cub3d.h>
#include <environment.h>
#include <mlx.h>
#include <X.h>
#include <hooks.h>
#include <stdlib.h>

void	setup(t_env *env, int ac, char **av)
{
	if (ac != 2)
		exit(1);
	if (!(env->mlx = mlx_init()))
		exit(1);
	parse_cub(&env->settings, av[1]);
	env->win =
	mlx_new_window(env->mlx, env->settings.width, env->settings.height, TITLE);
	if (!env->win)
		exit(1);
	mlx_hook(env->win, DestroyNotify, NoEventMask, &destroy_hook, NULL);
	mlx_key_hook(env->win, &key_hook, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
	mlx_loop(env->mlx);
}
