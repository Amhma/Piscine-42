/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:48:55 by amahla            #+#    #+#             */
/*   Updated: 2022/03/24 18:53:49 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
