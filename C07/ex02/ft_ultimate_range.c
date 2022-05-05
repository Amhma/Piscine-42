/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:03:35 by amahla            #+#    #+#             */
/*   Updated: 2022/03/21 16:41:50 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<limits.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	size;
	int				i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = (unsigned int)(max - min);
	*range = malloc(size * sizeof(int));
	if (!*range || size > INT_MAX)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return ((int)size);
}
