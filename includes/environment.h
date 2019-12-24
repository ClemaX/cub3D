/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:12:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 19:26:05 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <libft.h>
# include <mlx.h>
# include <X11/X.h>
# include <settings.h>
# include <vector.h>

# define TITLE		"cub3d"

# define KEY_ESCAPE	53
# define KEY_UP		13
# define KEY_DOWN	1
# define KEY_LEFT	0
# define KEY_RIGHT	2
# define KEY_ROT_L	123
# define KEY_ROT_R	124

# define S_MOVEMENT	5.0
# define S_ROTATION	2.0

# define ESCAPE		(1 << 0)
# define UP			(1 << 1)
# define DOWN		(1 << 2)
# define LEFT		(1 << 3)
# define RIGHT		(1 << 4)
# define ROT_LEFT	(1 << 5)
# define ROT_RIGHT	(1 << 6)

typedef struct		s_image
{
	void		*ptr;
	int			w;
	int			h;
	char		*data;
	int			bpp;
	int			ls;
	int			e;
}					t_image;


# define CELLS "012"

typedef enum	e_cell
{
	SPACE, WALL, SPRITE
}				t_cell;

typedef struct		s_map
{
	int			w;
	int			h;
	t_cell		*cells;
}				t_map;

typedef unsigned	t_keys;

# define HITBOX		0.2

typedef struct		s_player
{
	float		x;
	float		y;
	t_vector	dir;
	t_vector	plane;
	t_keys		input;
}					t_player;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	t_image		canvas;
	t_settings	settings;
	t_map		map;
	t_player	player;
	t_image		tex[5];
}					t_env;

typedef struct		s_obstacle
{
	t_cell		*cell;
	t_cardinal	face;
	int			offset;
	float		distance;
}					t_obstacle;

void				setup_env(t_env *env, int ac, char **av);
void				destroy_env(t_env *env);
int					read_map(t_env *env, char *line);
int					init_canvas(t_env *env);
void				draw_column(t_env *env, int x, t_obstacle obs);
void				refresh(t_env *env);
int					mouse_hook(int button, int x, int y, t_env *param);
int					key_enable(int key, t_env *env);
int					key_disable(int key, t_env *env);
int					loop_hook(t_env *env);
int					destroy_hook(t_env *param);
void				move_player(t_env *env, t_vector movement, float factor);
void				error(t_env *env);

#endif
