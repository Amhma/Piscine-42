/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:29:18 by samzil            #+#    #+#             */
/*   Updated: 2022/03/13 17:00:05 by rvrignon         ###   ########.fr       */
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
			if (a == 1 && (b == 1 || b == y))
				ft_putchar('A');
			else if (a == x && (b == 1 || b == y))
				ft_putchar('C');
			else if (a == 1 || a == x || b == 1 || b == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			a++;
			if (a == x + 1)
				ft_putchar('\n');
		}
		b++;
	}
}
