/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:06:51 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 04:30:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <environment.h>
#include <stdlib.h>
#include <errno.h>

static int	init_map(t_env *env, int width, int height)
{
	if (!width || !height)
	{
		errno = EFTYPE;
		return (0);
	}
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

static int	parse_line(t_env *env, t_list *line, int y)
{
	char	*s;
	int		x;
	int		pos;

	s = line->content;
	if (y == env->map.h - 1 && count_cells(line) != env->map.w)
		return (0);
	if (y >= env->map.h || *s++ != '1')
		return (0);
	env->map.cells[y * env->map.w] = WALL;
	x = 1;
	while (*s)
	{
		
	}
	return (s[-1] == '1' && x == env->map.w);
}

static int	parse_map(t_env *env, t_list *lines)
{
	t_list	*current;
	int		count;

	count = 0;
	current = lines;
	if (!(init_map(env, count_cells(current), ft_lstsize(lines))))
		return (0);
	while (current && parse_line(env, current, count++))
		current = current->next;
	ft_lstclear(&lines, &free);
	if (current)
	{
		errno = EFTYPE;
		return (0);
	}
	return(1);
}

int			read_map(t_env *env, char *line)
{
	static t_list	*lines;
	t_list			*new;

	if (*line)
	{
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
	free(line);
	if (!parse_map(env, lines))
		return (-1);
	return (0);
}
