/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/24 19:35:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 05:28:05 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define CELLS "01"
# define SPRITES "2"

typedef enum	e_cell
{
	SPACE, WALL
}				t_cell;

typedef struct	s_map
{
	int			w;
	int			h;
	t_cell		*cells;
}				t_map;

#endif
