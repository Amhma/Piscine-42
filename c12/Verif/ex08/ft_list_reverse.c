/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:40:15 by amahla            #+#    #+#             */
/*   Updated: 2022/03/25 19:55:17 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"
#include<unistd.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*elem;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	elem = *begin_list;
	while (elem)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	*begin_list = prev;
}
