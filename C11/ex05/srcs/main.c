/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:21:52 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 18:11:44 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"main.h"

int	ft_is_op(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-' || c == '%')
		return (1);
	return (0);
}

int	ft_check_op(char *op)
{
	if (ft_strlen(op) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	else if (!ft_is_op(*op))
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	ft_check_divider(char *op, char *arg)
{
	if ((*op == '/' && ft_atoi(arg) == 0))
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if ((*op == '%' && ft_atoi(arg) == 0))
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!ft_check_op(av[2]))
			return (0);
		if (!ft_check_divider(av[2], av[3]))
			return (0);
		(*ft_calculator(*av[2]))(ft_atoi(av[1]), ft_atoi(av[3]));
	}
	return (0);
}
