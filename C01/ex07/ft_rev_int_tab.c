/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:02:00 by amahla            #+#    #+#             */
/*   Updated: 2022/03/10 15:22:14 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (tab && i < size / 2)
	{
		temp = tab[i];
		tab [i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}
