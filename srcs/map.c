/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:06:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:13:53 by chamada     ###    #+. /#+    ###.fr     */
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
	return (map->cells != NULL);
}

int	parse_line(t_env *env, t_line *line, unsigned row)
{
	char		*s;
	unsigned	count;
	int			pos;

	s = line->content;
	if (row < env->map.size_y && s[env->map.size_x] && *s++ != '1')
		return (0);
	env->map.cells[row * env->map.size_x].type = WALL; 
	count = 1;
	while (*s)
	{
		if ((pos = ft_strpos(TYPES, *s)) != -1)
			env->map.cells[row * env->map.size_x + count++].type = pos;
		else if ((pos = ft_strpos(CARDINALS, *s)) != -1)
		{
			env->map.cells[row * env->map.size_x + count++].type = SPACE;
			env->player.pos = vector(count + 0.5, row + 0.5);
			env->player.dir = cardinal(pos);
			env->player.plane = cardinal(ft_strpos(PLANES, CARDINALS[pos]));
		}
		else if (!ft_isspace(*s))
			return (0);
		s++;
	}
	return (s[-1] == '1' && count == env->map.size_x);
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

int	parse_map(t_env *env, t_line *lines)
{
	t_line		*current;
	unsigned	count;

	count = 0;
	current = lines;
	init_map(&env->map, count_cells(current), ft_lstsize((t_list*)lines));
	while (current)
	{
		if (!parse_line(env, current, count++))
		{
			ft_lstclear((t_list**)&lines, &free);
			return (0);
		}
		current = current->next;
	}
	ft_lstclear((t_list**)&lines, &free);
	return (1);
}

int	read_map(t_env *env, char *line)
{
	static t_line	*lines;
	t_line			*new;

	if (*line)
	{
		if (*line != '1' || !(new = (t_line*)ft_lstnew(line)))
		{
			ft_lstclear((t_list**)&lines, &free);
			return (0);
		}
		ft_lstadd_back((t_list**)&lines, (t_list*)new);
		return (1);
	}
	parse_map(env, lines);
	return (0);
}
