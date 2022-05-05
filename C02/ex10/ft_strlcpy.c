/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:50:14 by amahla            #+#    #+#             */
/*   Updated: 2022/03/14 17:52:37 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *(src + i))
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = '\0';
	}
	i = 0;
	while (*(src + i))
		i++;
	return (i);
}
