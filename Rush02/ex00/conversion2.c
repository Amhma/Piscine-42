/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:59:17 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 18:52:28 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

int	check_format(char *str)
{
	int	i;

	i = 0;
	if (*str == '1')
	{
		i++;
		while (str[i])
		{
			if (str[i] != '0')
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_thousand(char *str, t_result **final, t_list *dico)
{
	while (dico)
	{
		if (ft_strlen(str) != 1 && ft_strlen(str) == ft_strlen(dico->number))
		{
			if (check_format(dico->number))
			{
				if (ft_strlen(dico->letter) == 0)
					return (0);
				ft_list_push_back2(final, dico->letter);
				return (1);
			}
		}
		else if (ft_strlen(str) == 1)
			return (1);
		dico = dico->next;
	}
	return (0);
}		

int	ft_unity(char c, t_result **final, t_list *dico)
{
	while (dico)
	{
		if (ft_strlen(dico->number) == 1 && c != '0')
		{
			if (ft_strncmp(&c, dico->number, 1) == 0)
			{
				if (ft_strlen(dico->letter) == 0)
					return (0);
				ft_list_push_back2(final, dico->letter);
				return (1);
			}
		}
		else if (c == '0')
			return (1);
		dico = dico->next;
	}
	return (0);
}

int	ft_tens(char *str, int *i, t_result **final, t_list *dico)
{
	while (dico)
	{
		if (ft_strlen(dico->number) == 2)
		{
			if (*str == '0')
				return (1);
			if (*str == '1' && ft_strncmp(str, dico->number, 2) == 0)
			{
				if (ft_strlen(dico->letter) == 0)
					return (0);
				ft_list_push_back2(final, dico->letter);
				(*i)++;
				return (1);
			}
			if (*str >= '2' && ft_strncmp(str, dico->number, 1) == 0)
			{
				if (ft_strlen(dico->letter) == 0)
					return (0);
				ft_list_push_back2(final, dico->letter);
				return (1);
			}
		}
		dico = dico->next;
	}
	return (0);
}

int	ft_hundred(char c, t_result **final, t_list *dico)
{
	if (!ft_unity(c, final, dico))
		return (0);
	while (dico)
	{
		if (ft_strcmp("100", dico->number) == 0)
		{
			if (ft_strlen(dico->letter) == 0)
				return (0);
			ft_list_push_back2(final, dico->letter);
			return (1);
		}
		dico = dico->next;
	}
	return (0);
}
