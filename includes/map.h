/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:21:22 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 21:47:54 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
# include <cell.h>

typedef struct	s_line
{
	char	*content;
	t_line	*next;
}				t_line;

typedef struct	s_map
{
	unsigned	size_x;
	unsigned	size_y;
	t_cell		*cells;
}				t_map;

int				read_map(t_map *map, char *line);

#endif
