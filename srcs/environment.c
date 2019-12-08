/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 00:45:05 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <cub3d.h>
#include <environment.h>
#include <hooks.h>
#include <stdlib.h>
#include <mlx.h>
#include <X.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include <libft.h>

void	error()
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	destroy_env(t_env *env)
{
	free(env->map.cells);
	free(env->settings.tex.ea);
	free(env->settings.tex.no);
	free(env->settings.tex.s);
	free(env->settings.tex.so);
	free(env->settings.tex.we);
}

void	setup_env(t_env *env, int ac, char **av)
{
	if (ac != 2)
	{
		errno = EINVAL;
		error();
	}
	if (!(env->mlx = mlx_init()))
		error();
	if (!parse_cub(env, av[1]))
		error();
	env->win =
	mlx_new_window(env->mlx, env->settings.width, env->settings.height, TITLE);
	if (!env->win)
		error();
	mlx_hook(env->win, DestroyNotify, NoEventMask, &destroy_hook, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &key_hook, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
	if (!init_canvas(env))
		error();
}
