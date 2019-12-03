/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:12:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 13:28:35 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <settings.h>
# include <map.h>

typedef struct	s_image
{
	void		*img;
	int			width;
	int			height;
}				t_image;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_settings	settings;
	t_map		map;
}				t_env;

void			setup(t_env *env, int ac, char **av);
int				parse_cub(t_env *env, const char *path);
void			clear_settings(t_settings *settings);

#endif
