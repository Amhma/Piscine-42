/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:37:01 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 19:29:25 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			res = *(s1 + i) - *(s2 + i);
			return (res);
		}
		i++;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int unsigned	i;
	int				res;

	i = 0;
	res = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			res = *(s1 + i) - *(s2 + i);
			return (res);
		}
		i++;
	}
	return (res);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}
