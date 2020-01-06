/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/01 01:28:32 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 01:36:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	char	swapped;
	t_list	*current;
	void	*temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (current->next)
		{
			if ((*cmp)(current->content, current->next->content) > 0)
			{
				temp = current->next->content;
				current->next->content = current->content;
				current->content = temp;
				swapped = 1;
			}
			current = current->next;
		}
		current = *begin_list;
	}
}
