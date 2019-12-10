/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 18:41:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <environment.h>
# include <fcntl.h>
# include <errno.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>

static int	parse_cub(t_env *env, char *path)
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

static int	load_image(t_env *env, t_image *img, char *path)
{
	const char *ext;

	if ((ext = ft_strrchr(path, '.')))
	{
		if (!ft_strncmp(ext, ".png", 4))
		{
			img->img =
			mlx_png_file_to_image(env->mlx, path, &img->width, &img->height);
		}
		else if (!ft_strncmp(ext, ".xpm", 4))
		{
			img->img =
			mlx_xpm_file_to_image(env->mlx, path, &img->width, &img->height);
		}
		else
			return (0);
		if (!img->img)
			return (0);
		img->data = mlx_get_data_addr(img->img, &img->bpp, &img->ls, &img->e);
	}
	else
		return (0);
	return (1);
}

static int	load_images(t_env *env)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (!load_image(env, &env->tex[i], env->settings.tex[i]))
		{
			errno = EFTYPE;
			return (0);
		}
		i++;
	}
	return (1);
}

void	setup_env(t_env *env, int ac, char **av)
{
	if (ac != 2)
	{
		errno = EINVAL;
		error();
	}
	if (!((env->mlx = mlx_init()) && parse_cub(env, av[1]) && load_images(env)))
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
	int	i;

	free(env->map.cells);
	i = 0;
	while (i < 5)
		free(env->settings.tex[i++]);
}
