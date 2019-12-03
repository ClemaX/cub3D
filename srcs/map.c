/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:06:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 17:10:30 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <libft.h>
#include <stdlib.h>

int	init_map(t_map *map, int size_x, int size_y)
{
	map->size_x = size_x;
	map->size_y = size_y;
	map->cells = malloc(sizeof(*map->cells) * size_x * size_y);
}

int	parse_line(t_map *map, t_line *lines)
{
	char		*pos;
	int			count;
	t_cell_type	type;
	t_dir		dir;
	t_cell		cell;

	if (*pos++ != '1')
		return (0);
	while (*pos)
	{
		if ((cell.type = ft_strpos(TYPES, *pos)) != -1)
			;
		else if ((dir = ft_strpos(DIRS, *pos)) != -1)
			;
		else
			return (0);
	}
}

int	count_cells(t_line *line)
{
	char	*pos;
	int		count;

	pos = line->content;
	count = 0;
	while (*pos)
		if (*pos++ == '1')
			count++;
	return (count);
}

int	parse_map(t_map *map, t_line *lines)
{
	t_line	*current;

	current = lines;
	init_map(map, count_cells(current), ft_lstsize(lines));
	while (current)
	{
		parse_line(map, current);
		current = current->next;
	}
	return (0);
}

int	read_map(t_map *map, char *line)
{
	static t_line	*lines;
	t_line			*new;

	if (*line)
	{
		if (*line != '1' || !(new = ft_lstnew(line)))
		{
			ft_lstclear(&lines, &free);
			return (0);
		}
		ft_lstadd_front(&lines, new);
		return (1);
	}
	else
		return (parse_map(map, lines));
}
