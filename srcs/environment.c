/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 22:15:12 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <environment.h>
# include <fcntl.h>
# include <errno.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>

static void	error()
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

static int	parse_cub(t_env *env, const char *path)
{
	int		fd;
	char	*ext;
	int		ret;
	char	*line;

	if (!(ext = ft_strrchr(path, '.')) || ft_strncmp(ext, ".cub", 4))
	{
		errno = EINVAL;
		return (0);
	}
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	clear_settings(&env->settings);
	while ((ret = get_next_line(fd, &line)) > 0 && *line != '1')
		if (!(parse_settings(&env->settings, line)))
			return (0);
	while (ret != -1 && read_map(env, line))
		if ((ret = get_next_line(fd, &line)) == -1)
			return (0);
	close(fd);
	return (1);
}

void	setup_env(t_env *env, int ac, char **av)
{
	if (ac != 2)
	{
		errno = EINVAL;
		error();
	}
	if (!(env->mlx = mlx_init()))
		error();
	if (!parse_cub(env, av[1]))
		error();
	env->player.input = 0;
	env->win =
	mlx_new_window(env->mlx, env->settings.width, env->settings.height, TITLE);
	if (!env->win)
		error();
	mlx_loop_hook(env->mlx, &loop_hook, env);
	mlx_hook(env->win, DestroyNotify, NoEventMask, &destroy_hook, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &key_enable, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, &key_disable, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
	if (!init_canvas(env))
		error();
}

void		destroy_env(t_env *env)
{
	free(env->map.cells);
	free(env->settings.tex.ea);
	free(env->settings.tex.no);
	free(env->settings.tex.s);
	free(env->settings.tex.so);
	free(env->settings.tex.we);
}
