/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:59:17 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 18:19:52 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

int	check_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_conversion2(char *nb, int *i, t_list *dico, t_result **final)
{
	if (nb[*i] != '0' && ft_strlen(nb + *i) % 3 == 0)
	{
		if (!ft_hundred(nb[*i], final, dico))
			return (0);
	}
	else if (ft_strlen(nb + *i) % 3 == 2)
	{
		if (!ft_tens(nb + *i, i, final, dico))
			return (0);
	}
	else if (ft_strlen(nb + *i) % 3 == 1)
	{
		if (!ft_unity(nb[*i], final, dico))
			return (0);
	}
	if (ft_strlen(nb + *i) % 3 == 1)
	{
		if (!ft_thousand(nb + *i, final, dico))
			return (0);
	}
	return (1);
}	

t_result	*ft_conversion(char *nb, t_list *dico)
{
	t_result	*final;
	int			i;

	i = 0;
	final = NULL;
	while (*nb == '0')
		nb++;
	while (nb[i])
	{
		if (ft_strlen(nb + i) % 3 == 0)
		{
			if (check_zero(nb + i))
				return (final);
			while (nb[i] && nb[i] == '0')
				i++;
		}
		if (!ft_conversion2(nb, &i, dico, &final))
			return (0);
		i++;
	}
	return (final);
}
