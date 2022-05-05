/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:40:52 by amahla            #+#    #+#             */
/*   Updated: 2022/03/14 17:36:01 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_hexa(unsigned char *str, unsigned int i, unsigned int size)
{	
	char			*base;
	unsigned int	j;

	j = 0;
	base = "0123456789abcdef";
	while (j < 16 && i + j < size)
	{
		if (!(j % 2))
			write(1, " ", 1);
		ft_putchar(base[str[i + j] / 16]);
		ft_putchar(base[str[i + j] % 16]);
		j++;
	}
	while (j < 16)
	{
		if (!(j % 2))
			write(1, "  ", 3);
		else
			write(1, " ", 2);
		j++;
	}
	write(1, " ", 1);
}

void	ft_puthexa(long long hex)
{	
	char	*base;

	base = "0123456789abcdef";
	if (hex >= 16)
		ft_puthexa(hex / 16);
	hex = base[hex % 16];
	write(1, &hex, 1);
}

void	ft_print_ptr(void *addr)
{
	int			i;
	long long	addr_ptr;

	i = 0;
	addr_ptr = (long long)addr;
	while (addr_ptr > 0)
	{
		addr_ptr /= 16;
		i++;
	}
	while (i <= 16)
	{
		ft_putchar('0');
		i++;
	}
	ft_puthexa((long long)addr);
	write(1, ":", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*str;

	str = (unsigned char *)addr;
	i = 0;
	while (str && *(str + i) && i < size)
	{
		j = 0;
		ft_print_ptr(addr + i);
		ft_putchar_hexa(str, i, size);
		while (j < 16 && i + j < size)
		{
			if (!(str[i + j] >= ' ' && str[i + j] <= '~'))
				write(1, ".", 1);
			else
				write(1, str + i + j, 1);
			j++;
		}
		i = i + j;
		write(1, "\n", 1);
	}
	return (addr);
}
