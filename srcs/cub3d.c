/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 22:19:14 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <ray.h>
#include <stdio.h>

void	refresh(t_env *env)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < env->settings.width)
	{
		init_ray(env, &ray, x);
		draw_column(env, x, cast_ray(env, &ray));
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->canvas.img, 0, 0);
}

int		main(int ac, char **av)
{
	t_env		env;

	setup_env(&env, ac, av);
	refresh(&env);
	mlx_do_key_autorepeatoff(env.mlx);
	mlx_loop(env.mlx);
	destroy_env(&env);
	return (0);
}
