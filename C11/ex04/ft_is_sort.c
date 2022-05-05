/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:01 by amahla            #+#    #+#             */
/*   Updated: 2022/03/24 11:31:25 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_desc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_asc(tab, length, f)
		|| ft_is_sort_desc(tab, length, f))
		return (1);
	return (0);
}
