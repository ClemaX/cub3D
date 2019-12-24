/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/24 19:35:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 19:40:14 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define CELLS "012"

typedef enum	e_cell
{
	SPACE, WALL, SPRITE
}				t_cell;

typedef struct	s_map
{
	int		w;
	int		h;
	t_cell	*cells;
}				t_map;

#endif
