/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:30:30 by amahla            #+#    #+#             */
/*   Updated: 2022/03/20 15:29:47 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_init_array(char **strs)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			*(strs[y] + x) = '.';
			x++;
		}
		y++;
	}
}

void	ft_print_array(char **strs)
{
	int	x;
	int	y;

	y = 0;
	while (strs[y])
	{
		x = 0;
		while (*(strs[y] + x))
		{
			write(1, strs[y] + x, 1);
			if (x != 3)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_split(char **strs, char *arg)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			*(strs[y] + x) = *(arg + i);
			i = i + 2;
			x++;
		}
		y++;
	}
}
