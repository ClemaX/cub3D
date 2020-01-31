/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:12:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 05:02:07 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <libft.h>
# include <mlx.h>
# include <settings.h>
# include <map.h>
# include <vector.h>

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define FOCUS_IN		9
# define FOCUS_OUT		10

# define NO_EVENT_M		0
# define KEY_PRESS_M	1
# define KEY_RELEASE_M	2
# define FOCUS_CHANGE_M	2097152

# define TITLE			"cub3d"

# define KEY_ESCAPE		53
# define KEY_UP			13
# define KEY_DOWN		1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ROT_L		123
# define KEY_ROT_R		124

# define FRAMERATE		60
# define FOV			0.66
# define HITBOX			0.2
# define S_MOVEMENT		0.1
# define S_ROTATION		0.1
# define MOUSE_SENS		500.0

# define ESCAPE			0b00000001
# define UP				0b00000010
# define DOWN			0b00000100
# define LEFT			0b00001000
# define RIGHT			0b00010000
# define ROT_LEFT		0b00100000
# define ROT_RIGHT		0b01000000

# ifndef MAX_WIDTH
#  define MAX_WIDTH		2880
# endif
# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 	1800
# endif

typedef enum		e_mode
{
	INTERACT, SAVE, BENCH
}					t_mode;

typedef struct		s_obstacle
{
	t_cell		*cell;
	t_cardinal	face;
	int			offset;
	float		distance;
}					t_obstacle;

typedef unsigned	t_keys;

typedef struct		s_image
{
	void	*ptr;
	char	*data;
	int		w;
	int		h;
	int		bpp;
	int		ls;
	int		e;
}					t_image;

typedef struct		s_stripe
{
	t_ivector	draw;
	t_ivector	end;
	t_ivector	tex;
	int			size;
}					t_stripe;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	float		*zbuffer;
	t_image		canvas;
	t_settings	settings;
	t_map		map;
	t_image		tex[5];
	t_keys		input;
	char		focus;
}					t_env;

int					benchmark(t_env *env);
void				setup_env(t_env *env, t_mode mode, const char *path);
int					load_images(t_env *env);
void				draw_stripe(t_env *env, t_stripe *stripe, t_image *tex);
void				refresh_env(t_env *env);
void				destroy_env(t_env *env);
void				draw_column(t_env *env, int x, t_obstacle obs);
void				error(t_env *env);

#endif
