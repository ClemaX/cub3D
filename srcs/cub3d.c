/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 18:36:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <mlx.h>
#include <ray.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_env		env;
	unsigned	x;
	unsigned	wall_height;
	int			start;
	unsigned	end;

	setup_env(&env, ac, av);
	t_color c = color(255, 255, 255);
	x = 0;
	while (x < env.settings.width)
	{
		double t = cast_ray(&env, x);
		printf("%lf ", t);
		wall_height = (int) env.settings.height / t;
		start = -wall_height / 2 + env.settings.height / 2;
		end = wall_height / 2 + env.settings.height / 2;
		if (start < 0)
			start = 0;
		if (end >= env.settings.height)
			end = env.settings.height - 1;
		//printf("%d: %d %u ", wall_height, start, end);
		while ((unsigned) start <= end)
		{
			put_canvas(&env, x, start, c.c);
			start++;
		}
		x++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
