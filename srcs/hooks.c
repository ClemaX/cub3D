/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:19:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 08:47:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>
#include <environment.h>
#include <stdlib.h>
#include <libftprintf.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	ft_printf("%4d, %4d: %d\n", x, y, button);
	return (0);
}

int	key_hook(int key, t_env *env)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

int	destroy_hook(void *param)
{
	(void)param;
	exit(0);
}
