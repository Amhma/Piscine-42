/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:41:27 by amahla            #+#    #+#             */
/*   Updated: 2022/03/10 19:39:31 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	t_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (tab && j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[j] > tab[i])
				t_swap(tab + j, tab + i);
			i++;
		}
		j++;
	}
}
