/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   settings.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:27:24 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 19:59:15 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <color.h>

typedef struct	s_settings
{
	int			width;
	int			height;
	struct		s_textures
	{
		char	*no;
		char	*so;
		char	*we;
		char	*ea;
		char	*s;
	}			tex;
	t_color		color_f;
	t_color		color_c;

}				t_settings;

void			clear_settings(t_settings *settings);
int				parse_settings(t_settings *settings, char *line);

#endif
