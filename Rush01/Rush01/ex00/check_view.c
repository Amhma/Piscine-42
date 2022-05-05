/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:36:45 by amahla            #+#    #+#             */
/*   Updated: 2022/03/20 17:31:28 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_up(char *view, char **solution, int x)
{
	int		y;
	int		count;
	char	c;

	y = 0;
	c = '0';
	count = 0;
	while (solution[y])
	{
		if (*(solution[y] + x) > c)
		{
			c = *(solution[y] + x);
			count++;
		}
		else if (*(solution[y] + x) == '.' && c != '4')
			return (1);
		y++;
	}
	if (count != *(view + x) - 48)
		return (0);
	return (1);
}

int	ft_check_down(char *view, char **solution, int x)
{
	int		y;
	int		count;
	char	c;

	y = 3;
	c = '0';
	count = 0;
	while (y >= 0)
	{
		if (*(solution[y] + x) > c)
		{
			c = *(solution[y] + x);
			count++;
		}
		else if (*(solution[y] + x) == '.' && c != '4')
			return (1);
		y--;
	}
	if (count != *(view + x) - 48)
		return (0);
	return (1);
}

int	ft_check_left(char *view, char **solution, int y)
{
	int		x;
	int		count;
	char	c;

	x = 0;
	c = '0';
	count = 0;
	while (*(solution[y] + x))
	{
		if (*(solution[y] + x) > c)
		{
			c = *(solution[y] + x);
			count++;
		}
		else if (*(solution[y] + x) == '.' && c != '4')
			return (1);
		x++;
	}
	if (count != *(view + y) - 48)
		return (0);
	return (1);
}

int	ft_check_right(char *view, char **solution, int y)
{
	int		x;
	int		count;
	char	c;

	x = 3;
	c = '0';
	count = 0;
	while (x >= 0)
	{
		if (*(solution[y] + x) > c)
		{
			c = *(solution[y] + x);
			count++;
		}
		else if (*(solution[y] + x) == '.' && c != '4')
			return (1);
		x--;
	}
	if (count != *(view + y) - 48)
		return (0);
	return (1);
}

int	ft_check_total_view(char **view, char **solution, int pos)
{
	int	x;
	int	y;

	x = pos % 4;
	y = pos / 4;
	if (ft_check_up(view[0], solution, x) && ft_check_down(view[1], solution, x)
		&& ft_check_left(view[2], solution, y)
		&& ft_check_right(view[3], solution, y))
		return (1);
	return (0);
}
