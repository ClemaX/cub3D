/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   settings.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 07:56:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 20:42:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <settings.h>
#include <vector.h>
#include <stdlib.h>
#include <errno.h>

static int	parse_res(t_settings *settings, char *line)
{
	int match;

	match = ft_sscanf(line, "R %d %d %*c", &settings->w, &settings->h);
	return (match == 2 && settings->w && settings->h);
}

static int	parse_imgs(t_settings *settings, char *line)
{
	int		match;
	char	*ext;

	if (!(ext = ft_strrchr(line, '.'))
	|| (ft_strncmp(ext, ".png", 5) && ft_strncmp(ext, ".xpm", 5)))
		return (0);
	if (!((match = ft_sscanf(line, "NO %ms %*c", &settings->tex[NORTH]))
	|| (match = ft_sscanf(line, "SO %ms %*c", &settings->tex[SOUTH]))
	|| (match = ft_sscanf(line, "WE %ms %*c", &settings->tex[WEST]))
	|| (match = ft_sscanf(line, "EA %ms %*c", &settings->tex[EAST]))))
		match = ft_sscanf(line, "S %ms %*c", &settings->tex[SPRITE_TEX]);
	return (match == 1);
}

static int	parse_colors(t_settings *settings, char *line)
{
	unsigned	r;
	unsigned	g;
	unsigned	b;

	if (ft_sscanf(line, "F %d, %d, %d %*c", &r, &g, &b) == 3)
		return (set_color(&settings->color_f, r, g, b));
	else if (ft_sscanf(line, "C %d, %d, %d %*c", &r, &g, &b) == 3)
		return (set_color(&settings->color_c, r, g, b));
	else
		return (0);
}

int			parse_settings(t_settings *settings, char *line)
{
	if (*line && !(parse_res(settings, line)
	|| parse_imgs(settings, line)
	|| parse_colors(settings, line)))
	{
		free(line);
		errno = EFTYPE;
		return (-1);
	}
	free(line);
	return (1);
}
