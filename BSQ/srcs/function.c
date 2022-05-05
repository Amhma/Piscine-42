/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:08:19 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/30 21:42:09 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str)
		write(1, &str[i++], 1);
}

int	ft_strheight(int **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i] && *tab[i] != -1)
		i++;
	return (i);
}

int	ft_strlen_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str)
	{	
		while (str[i] && i < ft_strlen(str) - 3
			&& (str[i] >= '0' && str[i] <= '9'))
			res = ((res * 10) + (str[i++] - '0'));
	}
	return (res);
}
