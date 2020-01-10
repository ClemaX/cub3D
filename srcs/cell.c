/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cell.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 04:25:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 05:28:30 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <sprite.h>

int parse_cell(t_map *map, char c, int *x, int y)
{
	int		type;
	t_list	*sprite;

	if ((type = ft_strpos(CELLS, c)) != -1)
		map->cells[y * map->w + (*x)++] = type;
	else if ((type = ft_strpos(SPRITES, c)) != -1)
	{
		if (!(sprite = new_sprite((*x)++, y, type)))
			return (0);
		ft_lstadd_back(&map->sprites, sprite);
	}
	else if ((type = ft_strpos(CARDINALS, c)) != -1 && map->player.x == -1)
	{
		map->cells[y * map->w + *x] = SPACE;
		map->player.x = (*x)++ + .5;
		map->player.y = y + .5;
		map->player.dir = cardinal(type);
		map->player.plane = cardinal(ft_strpos(CARDINALS, PLANES[type]));
	}
	else if (!ft_isspace(c))
		return (0);
	return (1);
}
