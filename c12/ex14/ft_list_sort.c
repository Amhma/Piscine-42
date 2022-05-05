/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:19:23 by amahla            #+#    #+#             */
/*   Updated: 2022/03/28 13:53:09 by amahla           ###   ########.fr       */
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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
