/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:07:44 by amahla            #+#    #+#             */
/*   Updated: 2022/03/19 18:02:42 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_check_total_view(char **view, char **solution, int pos);

int	ft_check_column(char **strs, int x, char c)
{
	int	y;

	y = 0;
	while (strs[y])
	{
		if (*(strs[y] + x) == c)
			return (0);
		y++;
	}
	return (1);
}

int	ft_check_row(char *str, char c)
{
	int	x;

	x = 0;
	while (*(str + x))
	{
		if (*(str + x) == c)
			return (0);
		x++;
	}
	return (1);
}

int	ft_backtracking(char **view, char **solution, int pos)
{
	int		x;
	int		y;
	char	c;

	x = pos % 4;
	y = pos / 4;
	c = '1';
	if (pos == 16)
		return (1);
	while (c <= '4')
	{
		if (ft_check_column(solution, x, c) && ft_check_row(solution[y], c))
		{
			*(solution[y] + x) = c;
			if (ft_check_total_view(view, solution, pos))
			{
				if (ft_backtracking(view, solution, pos + 1))
					return (1);
			}
		}
		c++;
	}
	*(solution[y] + x) = '.';
	return (0);
}

int	ft_check_error(char **solution)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (*(solution[y] + x) == '.')
			{
				write(2, "Error\n", 6);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
