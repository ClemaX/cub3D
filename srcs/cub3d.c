/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 01:06:32 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <ray.h>
#include <stdio.h>
#include <libft.h>
#include <canvas.h>
#include <sprite.h>

void	refresh(t_env *env)
{
	t_ray		ray;
	int			x;
	t_obstacle	obs;

	x = 0;
	while (x < env->canvas.w)
	{
		init_ray(&env->map.player, &ray, 2 * x / (float)env->canvas.w - 1);
		draw_column(env, x, (obs = cast_ray(&env->map, env->tex, &ray)));
		env->zbuffer[x] = obs.distance;
		x++;
	}
	draw_sprites(env);
}

int		main(int ac, const char **av)
{
	const t_mode	mode = get_mode(ac, av);
	static t_env	env;

	setup_env(&env, mode, av[1]);
	refresh(&env);
	if (mode == SAVE)
	{
		if (write_bmp("frame.bmp", env.canvas.data, env.canvas.w, env.canvas.h) != 1)
			error(&env);
		destroy_env(&env);
		return (0);
	}
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.ptr, 0, 0);
	mlx_do_key_autorepeatoff(env.mlx);
	mlx_loop(env.mlx);
	destroy_env(&env);
	return (0);
}
