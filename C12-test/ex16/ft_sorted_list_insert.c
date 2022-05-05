/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:57:17 by amahla            #+#    #+#             */
/*   Updated: 2022/03/30 12:03:07 by amahla           ###   ########.fr       */
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		elem = ft_create_elem(data);
		if (!elem)
			return ;
		elem->next = *begin_list;
		*begin_list = elem;
	}
	list_sort(begin_list, cmp);
}
