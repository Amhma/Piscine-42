/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:22:44 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 18:02:37 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(length * sizeof(int));
	if (!array)
		return (NULL);
	while (i < length)
	{
		array[i] = (*f)(tab[i]);
		i++;
	}
	return (array);
}
