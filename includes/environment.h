/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:12:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 03:57:48 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include <stdbool.h>
#include <color.h>
typedef struct	s_image
{
	void		*img;
	int			width;
	int			height;
}				t_image;

typedef struct	s_settings
{
	unsigned	width;
	unsigned	height;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	char		*tex_s;
	t_color		color_f;
	t_color		color_c;

}				t_settings;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_edge
{
	t_vector	a;
	t_vector	b;
}				t_edge;

typedef struct	s_cell
{
	bool		is_wall;
	bool		is_object;
	bool		has_edge[4];
	t_edge		*edge[4];
}				t_cell;

typedef struct	s_map
{
	unsigned	size_x;
	unsigned	size_y;
	t_cell		***cells;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_settings	settings;
}				t_env;

int				parse_cub(t_env *env, const char *path);

#endif
