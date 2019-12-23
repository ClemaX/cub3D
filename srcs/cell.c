/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cell.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:55:40 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 22:41:35 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>

inline void	set_cell(t_map *map, unsigned x, unsigned y, t_cell value)
{
	map->cells[y * map->w + x] = value;
}
