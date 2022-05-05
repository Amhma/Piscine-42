/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:29:27 by samzil            #+#    #+#             */
/*   Updated: 2022/03/12 12:45:25 by samzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	a;
	int	b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if ((a == 1 && b == 1) || ((a == x && x != 1)
					&& (b == y && y != 1)))
				ft_putchar('/');
			else if ((a == 1 && b == y) || (a == x && b == 1))
				ft_putchar(92);
			else if ((a > 1 && a < x) && (b > 1 && b < y))
				ft_putchar(' ');
			else
				ft_putchar('*');
			a++;
			if (a == x + 1)
				ft_putchar('\n');
		}
		b++;
	}
}
