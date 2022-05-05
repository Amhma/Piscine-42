/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:10:58 by amahla            #+#    #+#             */
/*   Updated: 2022/03/17 21:44:43 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	ft_putstr(av[ac - ac]);
	return (0);
}
