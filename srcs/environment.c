/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 01:40:36 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>

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
	while ((ret = get_next_line(fd, &line)) == 1 && *line != '1')
		if (!(parse_settings(&env->settings, line)))
			ret = -1;
	while (ret != -1 && (ret = read_map(env, line)) == 1)
		ret = get_next_line(fd, &line);
	close(fd);
	if (env->player.x == -1)
	{
		errno = EFTYPE;
		return (0);
	}
	return (ret != -1);
}

static int	load_image(t_env *env, t_image *img, char *path)
{
	const char *ext;

	if (path && (ext = ft_strrchr(path, '.')))
	{
		if (!ft_strncmp(ext, ".png", 4))
			img->ptr = mlx_png_file_to_image(env->mlx, path, &img->w, &img->h);
		else if (!ft_strncmp(ext, ".xpm", 4))
			img->ptr = mlx_xpm_file_to_image(env->mlx, path, &img->w, &img->h);
		else
			return (0);
		if (!img->ptr)
			return (0);
		img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->ls, &img->e);
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

t_mode	get_mode(int ac, const char **av)
{
	if (ac == 3)
	{
		if (!ft_strncmp(av[2], "--save", 7))
			return (SAVE);
		if (!ft_strncmp(av[2], "--bench", 8))
			return (BENCH);
	}
	if (ac != 2)
	{
		errno = EINVAL;
		error(0);
	}
	return (INTERACT);
}

void		setup_env(t_env *env, t_mode mode, const char *path)
{
	const Screen	*screen = DefaultScreenOfDisplay(XOpenDisplay(NULL));

	if (!(parse_cub(env, path) && (env->mlx = mlx_init()) && load_images(env)))
		error(env);
	env->player.input = 0;
	if (env->settings.w > screen->width)
		env->settings.w = screen->width;
	if (env->settings.h > screen->height)
		env->settings.h = screen->height;
	env->win =
	mlx_new_window(env->mlx, env->settings.w, env->settings.h, TITLE);
	if (!env->win || !init_canvas(env))
		error(env);
	mlx_loop_hook(env->mlx, (mode == INTERACT) ? &loop_hook : &benchmark, env);
	mlx_hook(env->win, DestroyNotify, NoEventMask, &destroy_hook, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &key_enable, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, &key_disable, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
}

void		destroy_env(t_env *env)
{
	int	i;

	if (env)
	{
		free(env->map.cells);
		i = 0;
		while (i < 5)
		{
			if (env->tex[i].ptr)
				mlx_destroy_image(env->mlx, env->tex[i].ptr);
			free(env->settings.tex[i]);
			i++;
		}
		if (env->canvas.ptr)
			mlx_destroy_image(env->mlx, env->canvas.ptr);
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
	}
}
