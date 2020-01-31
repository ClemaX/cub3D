/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:28:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 00:43:57 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <hooks.h>
#include <ray.h>
#include <sprite.h>
#include <canvas.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

static int	check_eof(int fd)
{
	int		ret;
	char	*line;

	if ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret != -1)
			errno = EFTYPE;
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

static int	parse_cub(t_env *env, const char *path)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	ret = 0;
	while (ret != -1 && (ret = get_next_line(fd, &line)) == 1 && *line != '1')
		ret = parse_settings(&env->settings, line);
	while (ret != -1 && (ret = read_map(&env->map, line)) == 1)
		ret = get_next_line(fd, &line);
	if (ret == 0)
		ret = check_eof(fd);
	close(fd);
	if (ret != -1 && (ret = env->map.player.x) == -1)
		errno = EFTYPE;
	return (ret != -1);
}

void		setup_env(t_env *env, t_mode mode, const char *path)
{
	if (!(parse_cub(env, path) && (env->mlx = mlx_init()) && load_images(env)))
		error(env);
	env->input = 0;
	if (env->settings.w > MAX_WIDTH)
		env->settings.w = MAX_WIDTH;
	if (env->settings.h > MAX_HEIGHT)
		env->settings.h = MAX_HEIGHT;
	env->win =
	mlx_new_window(env->mlx, env->settings.w, env->settings.h, TITLE);
	if (!env->win || !init_canvas(env))
		error(env);
	mlx_mouse_move(env->win, env->canvas.w / 2, env->canvas.h / 2);
	hooks_init(env, mode);
	mlx_do_key_autorepeatoff(env->mlx);
}

void		refresh_env(t_env *env)
{
	t_ray		ray;
	int			x;
	t_obstacle	obs;

	x = 0;
	while (x < env->canvas.w)
	{
		init_ray(&env->map.player, &ray, 2 * x / (float)env->canvas.w - 1);
		draw_column(env, x, (obs = cast_ray(&env->map, env->tex, &ray)));
		env->zbuffer[x] = obs.distance;
		x++;
	}
	draw_sprites(env);
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
	}
}
