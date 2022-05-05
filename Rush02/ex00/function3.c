/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:51:16 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 19:30:12 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

void	ft_remove_list(t_list **begin_list)
{
	t_list	*elem;

	while (*begin_list)
	{
		elem = *begin_list;
		*begin_list = (*begin_list)->next;
		free(elem->number);
		free(elem->letter);
		free(elem);
	}
	*begin_list = NULL;
}

void	ft_remove_list2(t_result **begin_list)
{
	t_result	*elem;

	while (*begin_list)
	{
		elem = *begin_list;
		*begin_list = (*begin_list)->next;
		free(elem);
	}
	*begin_list = NULL;
}

void	ft_remove(t_list **begin_list1, t_result **begin_list2)
{
	ft_remove_list(begin_list1);
	ft_remove_list2(begin_list2);
}

void	ft_putlist(t_result *begin_list)
{
	while (begin_list)
	{
		ft_putstr(begin_list->res);
		if (begin_list->next)
			write(1, " ", 1);
		begin_list = begin_list->next;
	}
	write(1, "\n", 1);
}
