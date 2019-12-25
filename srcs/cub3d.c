/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 03:04:26 by chamada     ###    #+. /#+    ###.fr     */
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
	while (x < env->settings.w)
	{
		init_ray(env, &ray, x);
		draw_column(env, x, cast_ray(env, &ray));
		x++;
	}
}

int				main(int ac, const char **av)
{
	const t_mode	mode = get_mode(ac, av);
	static t_env	env;

	setup_env(&env, mode, av[1]);
	refresh(&env);
	if (mode == SAVE)
	{
		write_bmp("frame.bmp", env.canvas.data, env.canvas.w, env.canvas.h);
		destroy_env(&env);
		return (0);
	}
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.ptr, 0, 0);
	mlx_do_key_autorepeatoff(env.mlx);
	mlx_loop(env.mlx);
	destroy_env(&env);
	return (0);
}
