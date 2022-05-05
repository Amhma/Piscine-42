/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:15:10 by amahla            #+#    #+#             */
/*   Updated: 2022/03/21 17:38:48 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_stock_str.h"
#include<unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while ((par + i)->str)
	{
		ft_putstr((par + i)->str);
		ft_putnbr((par + i)->size);
		write(1, "\n", 1);
		ft_putstr((par + i)->copy);
		i++;
	}
}
