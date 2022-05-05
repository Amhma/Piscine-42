/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:11:25 by amahla            #+#    #+#             */
/*   Updated: 2022/03/20 19:09:33 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_is_charset(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_strscpy(int size, char **strs, char *src, char *charset)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (*(src + i) && ft_is_charset(charset, *(src + i)))
			i++;
		while (*(src + i) && !ft_is_charset(charset, *(src + i)))
		{
			*(strs[y] + x) = *(src + i);
			x++;
			i++;
		}
		*(strs[y] + x) = '\0';
		y++;
	}
}

int	ft_count_char(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*(str + i) && !ft_is_charset(charset, *(str + i)))
		i++;
	return (i);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!*str)
		return (0);
	if (!*charset)
		return (1);
	while (*(str + i))
	{
		while (*(str + i) && ft_is_charset(charset, *(str + i)))
			i++;
		if (*(str + i))
			nb++;
		while (*(str + i) && !ft_is_charset(charset, *(str + i)))
			i++;
	}
	return (nb);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		y;
	int		i;
	int		size_split;

	y = 0;
	i = 0;
	size_split = ft_count_word(str, charset);
	split = malloc((size_split + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[size_split] = NULL;
	while (y < size_split)
	{	
		while (*(str + i) && ft_is_charset(charset, *(str + i)))
			i++;
		split[y] = malloc((ft_count_char(str + i, charset) + 1) * sizeof(char));
		if (!split[y])
			return (NULL);
		while (*(str + i) && !ft_is_charset(charset, *(str + i)))
			i++;
		y++;
	}
	ft_strscpy(size_split, split, str, charset);
	return (split);
}
