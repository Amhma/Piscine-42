/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:12:10 by amahla            #+#    #+#             */
/*   Updated: 2022/03/20 18:59:15 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str_cp;

	i = 0;
	str_cp = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str_cp)
		return (NULL);
	if (*(src + i))
	{
		while (*(src + i))
		{
			*(str_cp + i) = *(src + i);
			i++;
		}
		*(str_cp + i) = '\0';
	}
	return (str_cp);
}
