/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:11:13 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 15:46:52 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"operation.h"

void	ft_addition(int a, int b)
{
	long long	result;

	result = (long long)(a + b);
	ft_putnbr(result);
	ft_putchar('\n');
}

void	ft_substraction(int a, int b)
{
	long long	result;

	result = (long long)(a - b);
	ft_putnbr(result);
	ft_putchar('\n');
}

void	ft_multiplication(int a, int b)
{
	long long	result;

	result = (long long)(a * b);
	ft_putnbr(result);
	ft_putchar('\n');
}

void	ft_division(int a, int b)
{
	long long	result;

	result = (long long)(a / b);
	ft_putnbr(result);
	ft_putchar('\n');
}

void	ft_modulo(int a, int b)
{
	long long	result;

	result = (long long)(a % b);
	ft_putnbr(result);
	ft_putchar('\n');
}
