/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:33:28 by amahla            #+#    #+#             */
/*   Updated: 2022/03/14 13:22:02 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (*(dest + i))
			i++;
		while (src && *(src + j) && i + j < size - 1)
		{
			*(dest + i + j) = *(src + j);
			j++;
		}
		*(dest + i + j) = '\0';
	}
	while (*(src + j))
		j++;
	if (i > size)
		i = size;
	return (i + j);
}
