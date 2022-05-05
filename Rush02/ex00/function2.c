/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:51:16 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 19:30:01 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

int	ft_strlen(char *str);

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*str_cp;

	i = 0;
	str_cp = malloc((size + 1) * sizeof(char));
	if (!str_cp)
		return (NULL);
	while (src[i] && i < size)
	{
		str_cp[i] = src[i];
		i++;
	}
	str_cp[i] = '\0';
	return (str_cp);
}

t_result	*ft_create_elem2(char *result)
{
	t_result	*elem;

	elem = malloc(sizeof(t_result));
	if (!elem)
		return (NULL);
	else
	{
		elem->res = result;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_back2(t_result **begin_list, char *result)
{
	t_result	*elem;

	elem = *begin_list;
	if (!*begin_list)
		*begin_list = ft_create_elem2(result);
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem2(result);
	}
}

t_list	*ft_create_elem(char *number, char *letter)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	else
	{
		elem->number = number;
		elem->letter = letter;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, char *number, char *letter)
{
	t_list	*elem;

	elem = *begin_list;
	if (!*begin_list)
		*begin_list = ft_create_elem(number, letter);
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(number, letter);
	}
}
