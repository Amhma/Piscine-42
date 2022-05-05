/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:01:17 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 15:52:14 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"calculator.h"

void	ft_init_tab(void (*tab[])(int, int))
{
	tab[0] = &ft_addition;
	tab[1] = &ft_substraction;
	tab[2] = &ft_multiplication;
	tab[3] = &ft_division;
	tab[4] = &ft_modulo;
}

void	(*ft_calculator(char c))(int a, int b)
{
	void	(*tab[5])(int, int);

	ft_init_tab(tab);
	if (c == '+')
		return (tab[0]);
	else if (c == '-')
		return (tab[1]);
	else if (c == '*')
		return (tab[2]);
	else if (c == '/')
		return (tab[3]);
	return (tab[4]);
}
