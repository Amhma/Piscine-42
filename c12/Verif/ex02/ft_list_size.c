/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:15:35 by amahla            #+#    #+#             */
/*   Updated: 2022/03/24 17:43:18 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
