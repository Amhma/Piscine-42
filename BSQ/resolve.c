/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:33:59 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/28 20:08:35 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"resolve.h"
#include<stdio.h>

int	ft_test_square(char **map, char *info, int pos, int square)
{
	int	x;
	int	y;
	int	index_info;

	index_info = ft_strlen(info);
	y = pos / ft_strlen(map[0]);
	while (map[y] && y <= pos / ft_strlen(map[0]) + square)
	{
		x = pos % ft_strlen(map[0]);
		while (*(map[y] + x) && x <=  pos % ft_strlen(map[0]) + square)
		{
			if (*(map[y] + x) == info[index_info - 2])
				return (0);
			x++;
		}
		y++;
	}
	if (x < pos % ft_strlen(map[0]) + square || y < pos / ft_strlen(map[0]) + square)
		return (0);
	return (1);
}


int	ft_max_square(char **map, char *info, int pos, int last)
{
	int	len_max;

	len_max = last + 1;
	while (ft_test_square(map, info, pos, len_max))
		len_max++;
	len_max--;
	return (len_max);
}

int	ft_line(char **map, char *info, int	pos, int last)
{
	int	x;
	int	y;
	int	i;
	int	size;

	size = ft_strlen(info);
	i = 0;
	x = pos % ft_strlen(map[0]);
	y = pos / ft_strlen(map[0]);
	while (*(map[y] + x + i) && *(map[y] + x + i) != info[size - 2])
		i++;
	if (i <= last && x + last + i >= ft_strlen(map[0]) / 3)
		pos += ft_strlen(map[0]) - x;
	if (i <= last)
		pos += i;
	return (pos);
}

void	ft_resolve(char **map, char *info, int *res)
{
	int	pos;

	pos = 0;
	while (pos <= ft_atoi(info) * ft_strlen(map[0]))
	{
		pos = ft_line(map, info, pos, res[1]);
		if (ft_max_square(map, info, pos, res[1]) > res[1])
		{
			res[0] = pos;
			res[1] = ft_max_square(map, info, pos, res[1]);
		}
		pos++;
	}
}
