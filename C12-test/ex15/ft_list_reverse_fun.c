/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:00:42 by amahla            #+#    #+#             */
/*   Updated: 2022/03/29 18:07:49 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"

void	ft_swap(t_list *elem1, t_list *elem2)
{
	void	*temp;

	temp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = temp;
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (0);
}

unsigned int	ft_list_size(t_list *begin_list)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		ft_swap(ft_list_at(begin_list, i),
			ft_list_at(begin_list, size - 1 - i));
		i++;
	}
}
