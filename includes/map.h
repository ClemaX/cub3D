/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/24 19:35:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 00:48:20 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <player.h>

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
	t_player	player;
	t_cell		*cells;
	t_list		*sprites;
}				t_map;

int				read_map(t_map *map, char *line);
int 			parse_cell(t_map *map, char c, int *x, int y);

#endif
