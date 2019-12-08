/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 16:27:12 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <mlx.h>
#include <math.h>

int	main(int ac, char **av)
{
	t_env		env;
	double		camera_x;
	t_vector	dist;
	t_vector	ray_dir;
	t_vector	delta;

	setup_env(&env, ac, av);
	unsigned x = 0;
	t_color c = color(255, 255, 255);
	while (x < env.settings.width)
	{
		camera_x = 2 * x / (double) env.settings.width - 1;
		ray_dir.x = env.player.dir.x + env.player.plane.x * camera_x;
		ray_dir.y = env.player.dir.y + env.player.plane.y * camera_x;
		delta.x = fabs(1 / ray_dir.x);
		delta.y = fabs(1 / ray_dir.y);
		x++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
