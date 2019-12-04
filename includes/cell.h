/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cell.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:20:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 13:38:03 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H

# include <vector.h>

typedef struct	s_edge
{
	t_vector	a;
	t_vector	b;
}				t_edge;

# define TYPES "012"

typedef enum	e_cell_type
{
	SPACE, WALL, SPRITE
}				t_cell_type;

typedef struct	s_cell
{
	t_cell_type	type;
	bool		has_edge[4];
	t_edge		*edge[4];
}				t_cell;

#endif
