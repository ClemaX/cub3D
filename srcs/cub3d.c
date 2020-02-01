/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 02:51:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 02:57:42 by chamada     ###    #+. /#+    ###.fr     */
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
		errno = EINVAL;
		env_error(NULL);
	}
	else if (ac != 2
	|| !(ext = ft_strrchr(av[1], '.')) || ft_strncmp(ext, ".cub", 4))
	{
		errno = EINVAL;
		env_error(NULL);
	}
	return (INTERACT);
}

int				main(int ac, const char **av)
{
	const t_mode	mode = get_mode(ac, av);
	static t_env	env;

	env_init(&env, mode, av[1]);
	env_refresh(&env);
	if (mode == SAVE)
	{
		if (write_bmp("frame.bmp", env.canvas.data, env.canvas.w, env.canvas.h)
		!= 1)
			env_error(&env);
		env_destroy(&env);
		return (0);
	}
	mlx_put_image_to_window(env.mlx, env.win, env.canvas.ptr, 0, 0);
	mlx_loop(env.mlx);
	env_destroy(&env);
	return (0);
}
