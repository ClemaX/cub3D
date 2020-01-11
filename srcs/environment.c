/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 03:44:47 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

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
	ret = 0;
	while (ret != -1 && (ret = get_next_line(fd, &line)) == 1 && *line != '1')
		if (!(parse_settings(&env->settings, line)))
			ret = -1;
	while (ret != -1 && (ret = read_map(&env->map, line)) == 1)
		ret = get_next_line(fd, &line);
	close(fd);
	if (ret != -1 && (ret = env->map.player.x) == -1)
		errno = EFTYPE;
	return (ret != -1);
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
		error(NULL);
	}
	return (INTERACT);
}

void		setup_env(t_env *env, t_mode mode, const char *path)
{
	env->display = XOpenDisplay(NULL);
	env->screen = DefaultScreenOfDisplay(env->display);
	if (!(parse_cub(env, path) && (env->mlx = mlx_init()) && load_images(env)))
		error(env);
	env->input = 0;
	if (env->settings.w > env->screen->width)
		env->settings.w = env->screen->width;
	if (env->settings.h > env->screen->height)
		env->settings.h = env->screen->height;
	env->win =
	mlx_new_window(env->mlx, env->settings.w, env->settings.h, TITLE);
	if (!env->win || !init_canvas(env))
		error(env);
	mlx_loop_hook(env->mlx, (mode == INTERACT) ? &loop_hook : &benchmark, env);
	mlx_hook(env->win, DestroyNotify, NoEventMask, &destroy_hook, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &key_enable, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, &key_disable, env);
	mlx_mouse_hide();
	mlx_mouse_move(env->win, env->canvas.w / 2, env->canvas.h / 2);
	mlx_do_key_autorepeatoff(env->mlx);
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
		free(env->mlx);
		XCloseDisplay(env->display);
	}
}
