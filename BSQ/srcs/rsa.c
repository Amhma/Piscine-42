/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:42:39 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/30 23:09:44 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"

void	ft_change_map(char **map, char *info, int *res)
{
	int	x;
	int	y;
	int	index_info;

	index_info = ft_strlen(info);
	y = res[0] / ft_strlen(map[0]);
	while (y > res[0] / ft_strlen(map[0]) - res[1])
	{
		x = res[0] % ft_strlen(map[0]);
		while (x > res[0] % ft_strlen(map[0]) - res[1])
		{
			*(map[y] + x) = info[index_info - 1];
			x--;
		}
		y--;
	}
}

void	rsa(int fd)
{
	int		res[2];
	char	*info;
	char	**map;
	t_list	*buffer;

	buffer = NULL;
	res[0] = 0;
	res[1] = 0;
	if (ft_malloc(&map, &info, buffer, fd))
	{
		if (!check_map(map, info))
		{
			ft_putstr("map error\n");
			return ;
		}
		ft_resolve(map, info, res);
		ft_change_map(map, info, res);
		ft_print_array(map);
		ft_free_map(map);
	}
	else
		ft_putstr("map error\n");
	free(info);
}
