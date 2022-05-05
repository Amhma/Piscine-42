/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:10:47 by samzil            #+#    #+#             */
/*   Updated: 2022/03/12 12:45:05 by samzil           ###   ########.fr       */
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
			if ((a == 1 || a == x) && (b == 1 || b == y))
				ft_putchar('o');
			else if (a == 1 || a == x)
				ft_putchar('|');
			else if (b == 1 || b == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			a++;
			if (a == x + 1)
				ft_putchar('\n');
		}
		b++;
	}
}
