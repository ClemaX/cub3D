/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 10:07:34 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <environment.h>
#include <get_next_line.h>
#include <libft.h>
#include <mlx.h>
#include <libft.h>
#include <stdio.h>
#include <ft_sscanf.h>

int	parse_res(t_settings *settings, char *line)
{
	int match;

	match = ft_sscanf(line, "R %d %d", &settings->width, &settings->height);
	return (match == 2);
}

int	parse_imgs(t_settings *settings, char *line)
{
	int	match;

	if (!((match = ft_sscanf(line, "NO %m", &settings->tex.no))
	|| (match = ft_sscanf(line, "SO %m", &settings->tex.so))
	|| (match = ft_sscanf(line, "WE %m", &settings->tex.we))
	|| (match = ft_sscanf(line, "EA %m", &settings->tex.ea))))
		match = ft_sscanf(line, "S %m", &settings->tex.s);
	return (match == 1);
}

int	parse_colors(t_settings *settings, char *line)
{
	unsigned	r;
	unsigned	g;
	unsigned	b;

	if (ft_sscanf(line, "F %d, %d, %d", &r, &g, &b) == 3)
		return (set_color(&settings->color_f, r, g, b));
	else if (ft_sscanf(line, "C %d, %d, %d", &r, &g, &b) == 3)
		return (set_color(&settings->color_c, r, g, b));
	else
		return (0);
}

int	parse_settings(t_settings *settings, int fd)
{
	int			ret;
	char		*line;

	clear_settings(settings);
	while ((ret = get_next_line(fd, &line)) > 0 && *line != '1')
	{
		if (*line != '\0' && !(parse_res(settings, line)
		|| parse_imgs(settings, line)
		|| parse_colors(settings, line)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

int	parse_cub(t_settings *settings, const char *path)
{
	int		fd;
	char	*ext;

	ext = ft_strrchr(path, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4))
		return (0);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	parse_settings(settings, fd);
	close(fd);
	return (1);
}
