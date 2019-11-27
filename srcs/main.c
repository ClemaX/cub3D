/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 06:10:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdlib.h>
#include <mlx.h>
#include <X.h>
#include <environment.h>

#include <stdio.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	printf("%4d, %4d: %d\n", x, y, button);
	return (0);
}

int	key_hook(int key, t_env *param)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	return (0);
}

int	destroy_hook(void *param)
{
	(void)param;
	exit(0);
}

int	main(void)
{
	t_env	env;
	void	*img;

	if (!(env.mlx = mlx_init()))
		exit(1);
	if (!(env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, TITLE)))
		exit(1);
	mlx_hook(env.win, DestroyNotify, NoEventMask, &destroy_hook, NULL);
	mlx_key_hook(env.win, &key_hook, &env);
	int width;
	int height;
	img = mlx_png_file_to_image(env.mlx, "template.png", &width, &height);
	mlx_put_image_to_window(env.mlx, env.win, img, 10, 10);
	mlx_loop(env.mlx);
	return (0);
}
