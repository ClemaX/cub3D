/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 04:48:12 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <errno.h>
#include <unistd.h>

static t_mode	get_mode(int ac, const char **av)
{
	char	*ext;

	if (ac == 3)
	{
		if (!ft_strncmp(av[2], "--save", 7))
			return (SAVE);
		if (!ft_strncmp(av[2], "--bench", 8))
			return (BENCH);
	}
	else if (ac != 2
	|| !(ext = ft_strrchr(av[1], '.')) || ft_strncmp(ext, ".cub", 4))
	{
		errno = EINVAL;
		error(NULL);
	}
	return (INTERACT);
}

int				main(int ac, const char **av)
{
	const t_mode	mode = get_mode(ac, av);
	static t_env	env;

	setup_env(&env, mode, av[1]);
	refresh_env(&env);
	if (mode == SAVE)
	{
		if (write_bmp("frame.bmp", env.canvas.data, env.canvas.w, env.canvas.h)
		!= 1)
			error(&env);
		destroy_env(&env);
		return (0);
	}
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.ptr, 0, 0);
	mlx_loop(env.mlx);
	destroy_env(&env);
	return (0);
}
