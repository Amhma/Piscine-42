/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:06:15 by amahla            #+#    #+#             */
/*   Updated: 2022/03/24 14:06:47 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"
#include<stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	else
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}
