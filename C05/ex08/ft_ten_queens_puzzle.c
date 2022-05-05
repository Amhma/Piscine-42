/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:58:33 by amahla            #+#    #+#             */
/*   Updated: 2022/03/17 22:55:45 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_init_array(int array[][10])
{
	int		x;
	int		y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			array[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	ft_print_solution(int array[][10])
{
	int		x;
	int		y;
	char	res;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (array[y][x] != 0)
			{
				res = array[y][x] - 1 + 48;
				write(1, &res, 1);
				write(1, " ", 1);
			}
			else
				write(1, ". ", 2);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
}

int	ft_check_position(int array[][10], int y, int x)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		if (x + i < 10 && array[y][x + i] != 0)
			return (0);
		if (x - i >= 0 && array[y][x - i] != 0)
			return (0);
		if (y + i < 10 && array[y + i][x] != 0)
			return (0);
		if (y - i >= 0 && array[y - i][x] != 0)
			return (0);
		if (x - i >= 0 && y - i >= 0 && array[y - i][x - i] != 0)
			return (0);
		if (x + i < 10 && y + i < 10 && array[y + i][x + i] != 0)
			return (0);
		if (x - i >= 0 && y + i < 10 && array[y + i][x - i] != 0)
			return (0);
		if (x + i < 10 && y - i >= 0 && array[y - i][x + i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_backtracking(int array[][10], int col, int row, int *count)
{
	if (col > 9)
		return (1);
	while (row < 10)
	{
		if (ft_check_position(array, col, row))
		{
			array[col][row] = row + 1;
			if (ft_backtracking(array, col + 1, 0, count))
			{
				ft_print_solution(array);
				(*count)++;
			}
			array[col][row] = 0;
		}
		row++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10][10];
	int count;

	count = 0;
	ft_init_array(array);
	ft_backtracking(array, 0, 0, &count);
	return (count);
}

