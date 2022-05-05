/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:47:55 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 15:53:47 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

void	ft_putnbr(long long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	if (str)
	{
		while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == ' ')
			i++;
		while (*(str + i) == '+' || *(str + i) == '-')
		{
			if (*(str + i) == '-')
				sign *= -1;
			i++;
		}
		while (*(str + i) >= '0' && *(str + i) <= '9')
		{
			nb = nb * 10 + *(str + i) - 48;
			i++;
		}
	}
	return (nb * sign);
}
