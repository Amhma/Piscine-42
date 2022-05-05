/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:25:32 by amahla            #+#    #+#             */
/*   Updated: 2022/03/20 19:33:31 by amahla           ###   ########.fr       */
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

int	ft_size_malloc(int size, char **strs, char *sep)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < size)
	{
		i = i + ft_strlen(strs[y]);
		y++;
	}
	y = 0;
	while (y < size - 1)
	{
		i = i + ft_strlen(sep);
		y++;
	}
	return (i);
}

void	ft_strscpy(char *dest, int size, char **strs, char *sep)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (*(strs[y] + x))
		{
			*(dest + i) = *(strs[y] + x);
			x++;
			i++;
		}
		x = 0;
		while (y < size - 1 && *(sep + x))
		{
			*(dest + i) = *(sep + x);
			x++;
			i++;
		}
		y++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_str;
	char	*str;

	if (size <= 0)
	{
		str = malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	len_str = ft_size_malloc(size, strs, sep);
	str = malloc((len_str + 1) * sizeof(char));
	if (!sep)
		return (NULL);
	str[len_str] = '\0';
	ft_strscpy(str, size, strs, sep);
	return (str);
}
