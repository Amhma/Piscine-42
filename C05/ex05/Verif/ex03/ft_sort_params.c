/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:38:51 by amahla            #+#    #+#             */
/*   Updated: 2022/03/17 15:17:47 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putarray(char **str, int ac)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (*(str[j] + i))
		{
			write(1, str[j] + i, 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			res = *(s1 + i) - *(s2 + i);
			return (res);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				temp = av[i];
				av[i] = av[j];
				av[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_putarray(av, ac);
	return (0);
}
