/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/01 20:56:12 by chamada     ###    #+. /#+    ###.fr     */
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

int	parse_res(t_settings *settings, char **parts)
{
	if (*parts && ft_strncmp(*parts, "R", 2) == 0)
	{
		if (!parts[1] || !parts[2])
			return (-1);
		settings->width = ft_atoi(parts[1]);
		settings->height = ft_atoi(parts[2]);
		printf("Resolution: %dx%d\n", settings->width, settings->height);
		return (1);
	}
	return (0);
}

int	parse_imgs(t_settings *settings, char **parts)
{
	char	**dest;

	if (!*parts || !parts[1])
		return (0);
	if (ft_strncmp(*parts, "NO", 3) == 0)
		dest = (!settings->tex.no) ? &settings->tex.no : NULL;
	else if (ft_strncmp(*parts, "SO", 3) == 0)
		dest = (!settings->tex.so) ? &settings->tex.so : NULL;
	else if (ft_strncmp(*parts, "WE", 3) == 0)
		dest = (!settings->tex.we) ? &settings->tex.we : NULL;
	else if (ft_strncmp(*parts, "EA", 3) == 0)
		dest = (!settings->tex.ea) ? &settings->tex.ea : NULL;
	else if (ft_strncmp(*parts, "S", 3) == 0)
		dest = (!settings->tex.s) ? &settings->tex.s : NULL;
	else
		return (0);
	if (!dest)
		return (-1);
	printf("Image: [%-2s] %s\n", parts[0], parts[1]);
	*dest = ft_strdup(parts[1]);
	return (1);
}

int	parse_colors(t_settings *settings, char **parts)
{
	char	**rgb;
	t_color	*color;

	if (!*parts || !parts[1])
		return (0);
	if (ft_strncmp(*parts, "F", 2) == 0)
		color = &settings->color_f;
	else if (ft_strncmp(*parts, "C", 2) == 0)
		color = &settings->color_c;
	else
		return (0);
	rgb = ft_split(parts[1], ',');
	if (!(rgb[0] && rgb[1] && rgb[2]))
		return (-1);
	set_color(color, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	printf("Color: [%s] %#x\n", *parts, color->c);
	ft_strsclr(rgb);
	return (1);
}

int	parse_settings(t_settings *settings, int fd)
{
	int			ret;
	char		*line;
	char		**parts;

	clear_settings(settings);
	while ((ret = get_next_line(fd, &line)) > 0 && *line != '1')
	{
		if (!(parts = ft_split(line, ' ')))
			return (0);
		if (*parts && !(parse_res(settings, parts)
		|| parse_imgs(settings, parts)
		|| parse_colors(settings, parts)))
			printf("%s\n", line);
		ft_strsclr(parts);
		free(line);
	}
	return (1);
}

int	parse_cub(t_settings *settings, const char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd == -1)
		return (0);
	parse_settings(settings, fd);
	close(fd);
	return (1);
}
