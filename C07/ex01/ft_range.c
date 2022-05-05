/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:02:16 by amahla            #+#    #+#             */
/*   Updated: 2022/03/20 19:00:35 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	size;
	unsigned int	i;
	int				*array;

	i = 0;
	if (min >= max)
		return (NULL);
	size = (unsigned int)(max - min);
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
