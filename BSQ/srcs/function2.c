/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:58:50 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/30 22:44:01 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		free(map[y++]);
	free(map[y]);
	free(map);
}

void	ft_free_int(int **map_int, char **map)
{
	int	y;

	y = 0;
	while (map[y])
		free(map_int[y++]);
}
