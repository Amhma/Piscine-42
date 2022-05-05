/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:20:30 by amahla            #+#    #+#             */
/*   Updated: 2022/03/28 18:58:25 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*elem;
	t_list	*prev;
	t_list	*next;

	elem = *begin_list;
	prev = NULL;
	while (elem)
	{
		if ((*cmp)(elem->data, data_ref) == 0)
		{
			next = elem->next;
			(*free_fct)(elem->data);
			free(elem);
			elem = next;
			if (!prev)
				*begin_list = elem;
			else
				prev->next = elem;
		}
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}
