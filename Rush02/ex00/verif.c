/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:50:19 by amahla            #+#    #+#             */
/*   Updated: 2022/03/30 13:05:02 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isprintable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isnumber(str[i]))
		return (0);
	while (ft_isnumber(str[i]))
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != ':')
		return (0);
	while (str[i] == ' ' && str[i] == '\t')
		i++;
	if (!ft_isprintable(str[i]))
		return (0);
	while (ft_isprintable(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	ft_check_number(char *number, t_list *dico)
{
	if (check_zero(number))
	{
		while (dico)
		{
			if (ft_strcmp("0", dico->number) == 0 && ft_strlen(dico->letter))
			{
				ft_putstr(dico->letter);
				return (0);
			}
			dico = dico->next;
		}
		write(2, "Dict Error\n", 11);
		return (0);
	}
	while (*number)
	{
		if (!ft_isnumber(*number))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		number++;
	}
	return (1);
}
