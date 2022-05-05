/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:09:50 by amahla            #+#    #+#             */
/*   Updated: 2022/03/25 19:20:56 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"
#include<stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem;

	elem = begin_list;
	while (begin_list)
	{
		elem = begin_list;
		begin_list = begin_list->next;
		(*free_fct)(elem->data);
		free(elem);
	}
}
