/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:53:24 by amahla            #+#    #+#             */
/*   Updated: 2022/03/15 16:22:41 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (*(str + i))
	{
		j = i + 1;
		while (*(str + j))
		{
			if (*str == '+' || *str == '-'
				|| *(str + j) == '+' || *(str + j) == '-')
				return (0);
			if (*(str + i) == *(str + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;

	if (ft_check_base(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = nbr * -1;
		}
		else
			nb = nbr;
		if (nb >= ft_strlen(base))
			ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
}
