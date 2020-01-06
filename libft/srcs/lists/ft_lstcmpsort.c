/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstcmpsort.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 19:54:04 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 22:08:04 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void	lstsplit(t_list *lst, t_list **a, t_list **b)
{
	t_list	*slow;
	t_list	*fast;

	slow = lst;
	fast = lst;
	while (fast)
	{
		if (fast = fast->next)
		{
			slow = fast;
			fast = fast->next;
		}
	}
	a = lst;
	b = slow->next;
	slow->next = NULL;
}

static void	*lstmergecmp(t_list *a, t_list *b, int (*cmp)(void*, void*))
{
	t_list	*lst;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a, b) > 0)
	{
		a->next = lstmergecmp(a->next, b, cmp);
		lst = a;
	}
	else
	{
		b->next = a;
		lst = lstmergecmp(a, b->next, cmp);
	}
	return (lst);
}

void		ft_lstcmpsort(t_list **lst, int (*cmp)(void*, void*))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	head = lst;
	lstsplit(head, &a, &b);
	ft_lstcmpsort(a, cmp);
	ft_lstcmpsort(b, cmp);
	lst = lstmergecmp(a, b, cmp);
}
