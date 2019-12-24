/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:06:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 19:26:14 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <errno.h>

static int	init_map(t_env *env, int width, int height)
{
	env->player.x = -1;
	env->player.y = -1;
	env->map.w = width;
	env->map.h = height;
	env->map.cells = malloc(sizeof(*env->map.cells) * width * height);
	return (env->map.cells != NULL);
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

static int	parse_line(t_env *env, t_list *line, int row)
{
	char	*s;
	int		count;
	int		pos;

	s = line->content;
	if (row == env->map.h - 1 && count_cells(line) != env->map.w)
		return (0);
	if (row >= env->map.h || *s++ != '1')
		return (0);
	env->map.cells[row * env->map.w] = WALL;
	count = 1;
	while (*s)
	{
		if ((pos = ft_strpos(CELLS, *s)) != -1)
			env->map.cells[row * env->map.w + count++] = pos;
		else if ((pos = ft_strpos(CARDINALS, *s)) != -1 && env->player.x == -1)
		{
			env->map.cells[row * env->map.w + count++] = SPACE;
			env->player.x = count + 0.5;
			env->player.y = row + 0.5;
			env->player.dir = cardinal(pos);
			env->player.plane = cardinal(ft_strpos(CARDINALS, PLANES[pos]));
		}
		else if (!ft_isspace(*s))
			return (0);
		s++;
	}
	return (s[-1] == '1' && count == env->map.w);
}

static int	parse_map(t_env *env, t_list *lines)
{
	t_list	*current;
	int		count;

	count = 0;
	current = lines;
	if (!(init_map(env, count_cells(current), ft_lstsize(lines))))
		return (0);
	while (current)
	{
		if (!parse_line(env, current, count++))
		{
			ft_lstclear(&lines, &free);
			return (0);
		}
		current = current->next;
	}
	ft_lstclear(&lines, &free);
	return (1);
}

int			read_map(t_env *env, char *line)
{
	static t_list	*lines;
	t_list			*new;

	if (*line)
	{
		if (*line != '1')
		{
			errno = EFTYPE;
			return (-1);
		}
		if (!(new = ft_lstnew(line)))
		{
			ft_lstclear(&lines, &free);
			return (-1);
		}
		ft_lstadd_back(&lines, new);
		return (1);
	}
	if (!parse_map(env, lines))
	{
		errno = EFTYPE;
		return (-1);
	}
	return (0);
}
