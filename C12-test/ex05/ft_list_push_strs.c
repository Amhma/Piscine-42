/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:45:32 by amahla            #+#    #+#             */
/*   Updated: 2022/03/30 18:21:44 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		y;
	t_list	*begin_list;

	y = 0;
	begin_list = NULL;
	while (y < size)
	{
		ft_list_push_front(&begin_list, strs[y]);
		y++;
	}
	return (begin_list);
}
