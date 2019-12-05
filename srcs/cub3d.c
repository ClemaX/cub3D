/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:51:17 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <mlx.h>

int	main(int ac, char **av)
{
	t_env	env;

	setup_env(&env, ac, av);
	unsigned x = 0;
	t_color c = color(255, 255, 255);
	while (x < env.settings.width)
		put_canvas(&env, x++, env.settings.height - 1, c.c);
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
