/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:43:47 by amahla            #+#    #+#             */
/*   Updated: 2022/03/10 16:16:11 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void  ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_print_comb2(void)
{
	int	nbr1;
	int	nbr2;

	nbr1 = 0;
	while (nbr1 < 99)
	{
		nbr2 = nbr1 + 1;
		while (nbr2 <= 99)
		{
			if (nbr1 < 10)
				ft_putchar('0');
			ft_putnbr(nbr1);
			write(1, " ", 1);
			if (nbr2 < 10)
				ft_putchar('0');
			ft_putnbr(nbr2);
			if (nbr1 != 98)
				write(1, ", ", 2);
			nbr2++;
		}
		nbr1++;
	}
}
