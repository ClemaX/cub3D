/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   settings.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 07:56:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 13:47:41 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <settings.h>
#include <stdlib.h>
#include <ft_sscanf.h>

static int	parse_res(t_settings *settings, char *line)
{
	int match;

	match = ft_sscanf(line, "R %d %d", &settings->width, &settings->height);
	return (match == 2);
}

static int	parse_imgs(t_settings *settings, char *line)
{
	int	match;

	if (!((match = ft_sscanf(line, "NO %m", &settings->tex.no))
	|| (match = ft_sscanf(line, "SO %m", &settings->tex.so))
	|| (match = ft_sscanf(line, "WE %m", &settings->tex.we))
	|| (match = ft_sscanf(line, "EA %m", &settings->tex.ea))))
		match = ft_sscanf(line, "S %m", &settings->tex.s);
	return (match == 1);
}

static int	parse_colors(t_settings *settings, char *line)
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

void		clear_settings(t_settings *settings)
{
	settings->color_c.c = 0;
	settings->color_f.c = 0;
	settings->height = 0;
	settings->width = 0;
	settings->tex.ea = NULL;
	settings->tex.no = NULL;
	settings->tex.s = NULL;
	settings->tex.so = NULL;
	settings->tex.we = NULL;
}

int			parse_settings(t_settings *settings, char *line)
{
	if (*line && !(parse_res(settings, line)
	|| parse_imgs(settings, line)
	|| parse_colors(settings, line)))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
