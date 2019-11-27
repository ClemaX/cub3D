/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 05:40:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 11:23:45 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdbool.h>
# include <color.h>

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
	t_image		img_no;
	t_image		img_so;
	t_image		img_we;
	t_image		img_ea;
	t_image		img_s;
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


#endif