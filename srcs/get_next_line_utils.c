/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 03:03:04 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 11:39:47 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char *temp;

	if (!dst && !src)
		return (NULL);
	temp = dst;
	while (size--)
		*temp++ = *(char *)src++;
	return (dst);
}

int		search_end(char *s, size_t size, char **end)
{
	while (size && *s && *s != '\n' && size--)
		s++;
	if (size)
		return ((*(*end = s) == '\0') ? END : NEW_LINE);
	*end = NULL;
	return (CONTINUE);
}

t_fd	*del_fd(t_fd *curr, int fd)
{
	t_fd	*next;

	if (!curr)
		return (NULL);
	if (curr->fd == fd)
	{
		next = curr->next;
		free(curr->buffer);
		free(curr);
		return (next);
	}
	curr->next = del_fd(curr->next, fd);
	return (curr);
}

void	clear_fds(t_fd **fd_list)
{
	t_fd	*curr;

	if (fd_list)
	{
		while ((curr = *fd_list))
		{
			*fd_list = curr->next;
			free(curr->buffer);
			free(curr);
		}
	}
}

void	clear_words(t_words *words)
{
	t_words	*curr;

	while ((curr = words))
	{
		words = words->next;
		free(curr->content);
		free(curr);
	}
}
