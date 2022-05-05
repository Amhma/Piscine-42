/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:17:15 by amahla            #+#    #+#             */
/*   Updated: 2022/03/30 12:02:22 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
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
}
