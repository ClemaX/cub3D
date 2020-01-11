/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/24 19:35:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 04:38:12 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <vector.h>

# define CELLS "01"
# define SPRITES "2"

typedef struct	s_player
{
	float		x;
	float		y;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef enum	e_cell
{
	SPACE, WALL, SPRITE
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
int				parse_cell(t_map *map, char c, int *x, int y);
void			move_player(t_map *map, t_vector *movement);
t_vector		camera_transform(t_player *player, t_vector vector);

#endif
