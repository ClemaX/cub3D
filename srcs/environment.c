/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 20:22:52 by chamada     ###    #+. /#+    ###.fr     */
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

void	print_map(t_map map)
{
	unsigned i;

	i = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("%lf, %lf\n", map.player.pos.x, map.player.pos.y);
	while (i < map.size_y * map.size_x)
	{
		printf("%d ", map.cells[i++].type);
		if (i % map.size_x == 0)
			printf("\n");
	}
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
		exit(1);
	if (!(env->mlx = mlx_init()))
		exit(1);
	parse_cub(env, av[1]);
	print_map(env->map);
	env->win =
	mlx_new_window(env->mlx, env->settings.width, env->settings.height, TITLE);
	if (!env->win)
		exit(1);
	mlx_hook(env->win, DestroyNotify, NoEventMask, &destroy_hook, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &key_hook, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
	init_canvas(env);
}
