/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   settings.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:27:24 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:21:27 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <color.h>

# define SPRITE_TEX	4

typedef struct	s_settings
{
	int		w;
	int		h;
	char	*tex[5];
	t_color	color_f;
	t_color	color_c;
}				t_settings;

void			clear_settings(t_settings *settings);
int				parse_settings(t_settings *settings, char *line);

#endif
