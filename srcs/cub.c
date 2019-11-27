/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 11:25:41 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <environment.h>
#include <cub.h>
#include <get_next_line.h>
#include <libft.h>
#include <mlx.h>
#include <libft.h>

int	parse_res(t_settings *settings, char **parts)
{
	if (*parts && ft_strncmp(*parts, "R", 2) && parts[1] && parts[2])
	{
		settings->width = ft_atoi(parts[1]);
		settings->height = ft_atoi(parts[2]);
		return (1);
	}
	return (0);
}

int	parse_imgs(void *mlx, t_settings *settings, char **parts)
{
	t_image		*img;

	img = NULL;
	if (!settings->img_no.img && ft_strncmp(*parts, "NO", 3))
		*img = settings->img_no;
	else if (!settings->img_so.img && ft_strncmp(*parts, "SO", 3))
		*img = settings->img_so;
	else if (!settings->img_we.img && ft_strncmp(*parts, "WE", 3))
		*img = settings->img_we;
	else if (!settings->img_ea.img && ft_strncmp(*parts, "EA", 3))
		*img = settings->img_ea;
	else if (!settings->img_s.img && ft_strncmp(*parts, "S", 3))
		*img = settings->img_s;
	else
		return (0);
	img->img = mlx_png_file_to_image(mlx, parts[1], &img->width, &img->height);
	return (1);
}

int	parse_colors(t_settings *settings, char **parts)
{
	char	**values;

	if (*parts && ft_strncmp(*parts, "F", 2) && parts[1])
	{
		values = ft_split(*parts, ',');
		if (values[0] && values[1] && values[2])
		{
			settings->color_c.rgb.r = ft_atoi(values[0]);
			settings->color_c.rgb.g = ft_atoi(values[1]);
			settings->color_c.rgb.b = ft_atoi(values[2]);
		}
	}
	return (0);
}

int	parse_cub(char *path, void *mlx)
{
	const int	fd = open(path, O_RDONLY);
	t_settings	s;
	char		*line;
	char		**parts;

	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(parts = ft_split(line, ' ')))
			return (0);
		if (parse_res(&s, parts)
		|| parse_imgs(mlx, &s, parts)
		|| parse_colors(&s, parts))
			continue;
	}
	close(fd);
	return (1);
}
