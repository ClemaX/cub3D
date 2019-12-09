/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:12:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:00:16 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <settings.h>
# include <cell.h>
# include <vector.h>

# define TITLE	"cub3d"

# define ESCAPE	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2

typedef struct	s_image
{
	void		*img;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			ls;
	int			e;
}				t_image;

typedef struct	s_map
{
	unsigned	size_x;
	unsigned	size_y;
	t_cell		*cells;
}				t_map;


typedef struct	s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_image		canvas;
	t_settings	settings;
	t_map		map;
	t_player	player;
}				t_env;

void			setup_env(t_env *env, int ac, char **av);
void			destroy_env(t_env *env);
void			clear_settings(t_settings *settings);
int				read_map(t_env *env, char *line);
int				init_canvas(t_env *env);
void			put_canvas(t_env *env, int x, int y, unsigned int color);
void			refresh(t_env *env);

#endif
