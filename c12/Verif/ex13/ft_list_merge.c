/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:04:00 by amahla            #+#    #+#             */
/*   Updated: 2022/03/28 12:14:45 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*elem;

	elem = *begin_list1;
	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		while (elem)
		{
			if (!(elem->next))
			{
				elem->next = begin_list2;
				return ;
			}
			elem = elem->next;
		}
	}
}
