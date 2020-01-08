/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:12:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 23:39:29 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <libft.h>
# include <mlx.h>
# include <X11/X.h>
# include <settings.h>
# include <player.h>
# include <image.h>
# include <vector.h>
# include <map.h>

# define TITLE		"cub3d"

# define KEY_ESCAPE	53
# define KEY_UP		13
# define KEY_DOWN	1
# define KEY_LEFT	0
# define KEY_RIGHT	2
# define KEY_ROT_L	123
# define KEY_ROT_R	124

# define HITBOX		0.2
# define S_MOVEMENT	5.0
# define S_ROTATION	2.0

# define ESCAPE		1
# define UP			2
# define DOWN		4
# define LEFT		8
# define RIGHT		16
# define ROT_LEFT	32
# define ROT_RIGHT	64

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

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	t_obstacle	*zbuffer;
	t_image		canvas;
	t_settings	settings;
	t_map		map;
	t_player	player;
	t_image		tex[5];
	t_list		*sprites;
}					t_env;

int					benchmark(t_env *env);
t_mode				get_mode(int ac, const char **av);
void				setup_env(t_env *env, t_mode mode, const char *path);
void				destroy_env(t_env *env);
int					read_map(t_env *env, char *line);
int					init_canvas(t_env *env);
void				draw_column(t_env *env, int x);
void				refresh(t_env *env);
int					mouse_hook(int button, int x, int y, t_env *param);
int					key_enable(int key, t_env *env);
int					key_disable(int key, t_env *env);
int					loop_hook(t_env *env);
int					destroy_hook(t_env *param);
void				move_player(t_env *env, t_vector movement);
void				error(t_env *env);
int					load_images(t_env *env);
int 				parse_cell(t_env *env, char c, int *x, int y);
t_vector			camera_transform(t_env *env, t_vector vector);

#endif
