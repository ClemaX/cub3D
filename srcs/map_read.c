/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_read.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:06:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 07:06:07 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <errno.h>

static int	init_map(t_map *map, int width, int height)
{
	if (!width || !height)
	{
		errno = EFTYPE;
		return (0);
	}
	map->player.x = -1;
	map->player.y = -1;
	map->w = width;
	map->h = height;
	map->cells = malloc(sizeof(*map->cells) * width * height);
	return (map->cells != NULL);
}

static int	count_cells(t_list *line)
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

static int	parse_line(t_map *map, t_list *line, int y)
{
	char	*s;
	int		x;

	s = line->content;
	if (y == map->h - 1 && count_cells(line) != map->w)
		return (0);
	if (y >= map->h || *s++ != '1')
		return (0);
	map->cells[y * map->w] = WALL;
	x = 1;
	while (*s)
		if (parse_cell(map, *s++, &x, y) != 1)
			return (0);
	return (s[-1] == '1' && x == map->w);
}

static int	parse_map(t_map *map, t_list *lines)
{
	t_list	*current;
	int		count;

	count = 0;
	current = lines;
	if (!(init_map(map, count_cells(current), ft_lstsize(lines))))
	{
		ft_lstclear(&lines, &free);
		return (0);
	}
	while (current && parse_line(map, current, count++))
		current = current->next;
	ft_lstclear(&lines, &free);
	if (current)
	{
		errno = EFTYPE;
		return (0);
	}
	return (1);
}

int			read_map(t_map *map, char *line)
{
	static t_list	*lines;
	t_list			*new;

	if (!*line)
	{
		free(line);
		return (parse_map(map, lines) ? 0 : -1);
	}
	if (*line != '1')
	{
		free(line);
		ft_lstclear(&lines, &free);
		errno = EFTYPE;
		return (-1);
	}
	if (!(new = ft_lstnew(line)))
	{
		free(line);
		ft_lstclear(&lines, &free);
		return (-1);
	}
	ft_lstadd_back(&lines, new);
	return (1);
}
