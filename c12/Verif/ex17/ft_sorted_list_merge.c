/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:56:58 by amahla            #+#    #+#             */
/*   Updated: 2022/03/30 11:55:36 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"
#include<stdlib.h>

void	ft_swap_list(t_list **elem, t_list **next)
{
	t_list	*swap;

	swap = (*next)->next;
	(*next)->next = *elem;
	(*elem)->next = swap;
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*elem;
	t_list	*prev;
	t_list	*next;

	elem = *begin_list;
	prev = NULL;
	while (elem && elem->next)
	{
		next = elem->next;
		if ((*cmp)(elem->data, next->data) > 0)
		{
			ft_swap_list(&elem, &next);
			if (!prev)
				*begin_list = next;
			else
				prev->next = next;
			elem = *begin_list;
			prev = NULL;
		}
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list	*elem;

	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		elem = *begin_list1;
		while (elem->next)
			elem = elem->next;
		elem->next = begin_list2;
	}
	list_sort(begin_list1, cmp);
}
