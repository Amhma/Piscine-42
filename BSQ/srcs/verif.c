/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:32:23 by amahla            #+#    #+#             */
/*   Updated: 2022/03/30 23:07:29 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"

int	ft_strlen(char *str);

int	ft_is_not(char *info, char c)
{
	int	i;

	i = ft_strlen(info) - 4;
	if (c == info[i] || c == info[i + 1] || c == info[i + 2] || c == '\n')
		return (1);
	return (0);
}

int	check_char(char *info, char **map)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	i = ft_strlen(info) - 4;
	if (info[i] == info[i + 1] || info[i] == info[i + 2])
		return (0);
	else if (info[i + 1] == info[i + 2])
		return (0);
	while (map[y])
	{
		x = 0;
		while (*(map[y] + x))
		{
			if (!ft_is_not(info, *(map[y] + x)))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(char **map, char *info)
{
	int	i;

	i = 0;
	if (ft_strlen(info) <= 3 || !ft_strlen(map[0]))
		return (0);
	if (!check_char(info, map))
		return (0);
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
