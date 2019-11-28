/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 04:03:20 by chamada     ###    #+. /#+    ###.fr     */
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
	if (!settings->tex_no && ft_strncmp(*parts, "NO", 3) == 0)
		dest = &settings->tex_no;
	else if (!settings->tex_so && ft_strncmp(*parts, "SO", 3) == 0)
		dest = &settings->tex_so;
	else if (!settings->tex_we && ft_strncmp(*parts, "WE", 3) == 0)
		dest = &settings->tex_we;
	else if (!settings->tex_ea && ft_strncmp(*parts, "EA", 3) == 0)
		dest = &settings->tex_ea;
	else if (!settings->tex_s && ft_strncmp(*parts, "S", 3) == 0)
		dest = &settings->tex_s;
	else
		return (0);
	printf("Image: [%-2s] %s\n", parts[0], parts[1]);
	*dest = ft_strdup(parts[1]);
	return (1);
}

int	parse_colors(t_settings *settings, char **parts)
{
	char	**values;
	t_color	*color;

	if (!*parts || !parts[1])
		return (0);
	if (ft_strncmp(*parts, "F", 2) == 0)
		color = &settings->color_f;
	else if (ft_strncmp(*parts, "C", 2) == 0)
		color = &settings->color_c;
	else
		return (0);
	values = ft_split(parts[1], ',');
	if (values[0] && values[1] && values[2])
	{
		color->r = ft_atoi(values[0]);
		color->g = ft_atoi(values[1]);
		color->b = ft_atoi(values[2]);
		printf("Color: [%s] %#x\n", *parts, settings->color_f.r);
	}
	else
		return (-1);
	ft_strsclr(values);
	return (1);
}

int	parse_settings(t_env *env, int fd)
{
	int			ret;
	char		*line;
	char		**parts;

	env->settings.tex_no = NULL;
	env->settings.tex_so= NULL;
	env->settings.tex_we = NULL;
	env->settings.tex_ea = NULL;
	env->settings.tex_s = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && *line != '1')
	{
		if (!(parts = ft_split(line, ' ')))
			return (0);
		if (*parts && !(parse_res(&env->settings, parts)
		|| parse_imgs(&env->settings, parts)
		|| parse_colors(&env->settings, parts)))
			printf("%s\n", line);
		ft_strsclr(parts);
		free(line);
	}
	return (1);
}

int	parse_cub(t_env *env, const char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd == -1)
		return (0);
	parse_settings(env, fd);
	close(fd);
	return (1);
}
