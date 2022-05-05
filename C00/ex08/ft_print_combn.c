/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:00:50 by amahla            #+#    #+#             */
/*   Updated: 2022/03/10 22:55:29 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_array(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_next_solution(int *tab, int n)
{
	int	i;

	i = n - 1;
	while (tab[i] >= 9 - ( n - (i + 1)) && i > 0)
		i--;
	tab[i]++;
	i++;
	while (i < n && i >= 0)
	{
		tab[i] = tab[i - 1] + 1; 
		i++;
	}
}

void	ft_print_combn(int n)
{
	int tab[9];
	int	i;

	i = 0;
	while (i < 9)
	{
		tab[i] = i;
		i++;
	}
	i = n - 1;
	if (n < 1 || n > 9)
		return ;
	while (tab[i] <= 9)
	{
		ft_print_array(tab, n);
		if (tab[0] != 9 - (n - 1))
			write(1, ", ", 2);	
		tab[i]++;
		if (tab[i] > 9)
			ft_next_solution(tab, n);
	}
}
