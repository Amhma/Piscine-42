/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:42:39 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/28 19:23:42 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa.h"
#include<stdio.h>

void	ft_change_map(char **map, char *info, int *res)
{
	int	x;
	int	y;
	int	index_info;

	index_info = ft_strlen(info);
	y = res[0] / ft_strlen(map[0]);
	while (y <= res[0] / ft_strlen(map[0]) + res[1])
	{
		x = res[0] % ft_strlen(map[0]);
		while (x <= res[0] % ft_strlen(map[0]) + res[1])
		{
			*(map[y] + x) = info[index_info - 1];
			x++;
		}
		y++;
	}
}

void	rsa(char *av)
{
	int		fd;
	int		res[2];
	char	*info;
	char	**map;
	t_list	*buffer;

	buffer = NULL;
	res[0] = 0;
	res[1] = 0;
	fd = open(av, O_RDONLY);
	if (fd > 1024 && fd < 0)
		return ;
	if (ft_malloc(&map, &info, buffer, fd))
	{
		printf("%c\n", info[2]);
		ft_resolve(map, info, res);
		ft_change_map(map, info, res);
		ft_print_array(map, ft_atoi(info));
	}
}
