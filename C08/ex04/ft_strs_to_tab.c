/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:42:39 by amahla            #+#    #+#             */
/*   Updated: 2022/03/21 20:17:09 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_stock_str.h"
#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	i = 0;
	if (ac < 0)
		ac = 0;
	array = malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
		return (NULL);
	while (i < ac)
	{
		(array + i)->copy = ft_strdup(av[i]);
		(array + i)->size = ft_strlen(av[i]);
		(array + i)->str = av[i];
		i++;
	}
	(array + i)->str = 0;
	return (array);
}
