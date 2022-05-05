/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:52:28 by amahla            #+#    #+#             */
/*   Updated: 2022/03/14 19:23:48 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(unsigned char c)
{
	if (!(c >= ' ' && c <= '~'))
		return (0);
	return (1);
}

void	ft_putchar_hexa(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_char_is_printable(str[i]))
		{
			ft_putchar('\\');
			ft_putchar_hexa((unsigned char)str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
