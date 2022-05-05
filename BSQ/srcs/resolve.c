/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:33:59 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/30 21:44:30 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"

int	ft_strlen_int(int *tab);

int	**create_map_int(char **map)
{
	int	size_col;
	int	**map_int;
	int	y;

	y = 0;
	size_col = 0;
	while (map[size_col])
		size_col++;
	map_int = malloc((size_col) * sizeof(int *));
	if (!map_int)
		return (NULL);
	while (y < size_col)
	{
		map_int[y] = malloc((ft_strlen(map[0])) * sizeof(int));
		if (!map_int[y])
			return (NULL);
		y++;
	}
	return (map_int);
}

int	ft_min(int i, int j, int k)
{
	if (i <= j && i <= k)
		return (i + 1);
	else if (j <= i && j <= k)
		return (j + 1);
	return (k + 1);
}

int	ft_max_square(int **map, char **map_char, int pos, char c)
{
	int	x;
	int	y;

	x = pos % ft_strlen(map_char[0]);
	y = pos / ft_strlen(map_char[0]);
	if (*(map_char[y] + x) == c)
		*(map[y] + x) = 0;
	else if (x == 0 || y == 0)
		(*(map[y] + x)) = 1;
	else
		*(map[y] + x) = ft_min(*(map[y - 1] + x),
				*(map[y] + x - 1), *(map[y - 1] + x - 1));
	return (*(map[y] + x));
}

void	ft_resolve(char **map, char *info, int *res)
{
	int	pos;
	int	**map_int;
	int	size;
	int	solution;

	size = ft_strlen(info);
	map_int = create_map_int(map);
	pos = 0;
	while (pos < ft_strlen_map(map) * ft_strlen(map[0]))
	{
		solution = ft_max_square(map_int, map, pos, info[size - 2]);
		if (solution > res[1])
		{
			res[0] = pos;
			res[1] = solution;
		}
		pos++;
	}
	ft_free_int(map_int, map);
}
