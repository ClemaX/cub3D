/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 13:30:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <mlx.h>
#include <ray.h>
#include <stdio.h>

void	refresh(t_env *env)
{
	int		x;
	int		wall_height;
	int		start;
	int		end;
	int		y;
	t_color	c;

	x = 0;
	while (x < env->settings.width)
	{
		double t = cast_ray(env, x);
		if (t < 1)
			t = 1;
		wall_height = (int) env->settings.height / t;
		start = -wall_height / 2 + env->settings.height / 2;
		end = wall_height / 2 + env->settings.height / 2;
		if (start < 0)
			start = 0;
		if (end >= env->settings.height)
			end = env->settings.height - 1;
		y = 0;
		while (y < env->settings.height && y <= start)
			put_canvas(env, x, y++, 0);
		while (start <= end)
		{
			c = color(255 / t, 255 / t, 255 / t);
			put_canvas(env, x, start++, c.c);
		}
		y = end + 1;
		while (y < env->settings.height)
			put_canvas(env, x, y++, 0);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->canvas.img, 0, 0);
}

int		main(int ac, char **av)
{
	t_env		env;

	setup_env(&env, ac, av);
	refresh(&env);
	mlx_do_key_autorepeaton(env.mlx);
	mlx_loop(env.mlx);
	return (0);
}
