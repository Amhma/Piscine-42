/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:48:59 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/30 23:12:47 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"

void	rsa(int fd);

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	i = 1;
	if (ac == 1)
		rsa(0);
	else
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd > 1024 || fd < 0)
			{
				ft_putstr("map error\n");
				return (0);
			}
			rsa(fd);
			close(fd);
			i++;
		}
	}
	return (0);
}
