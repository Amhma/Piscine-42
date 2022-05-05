/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:21:40 by amahla            #+#    #+#             */
/*   Updated: 2022/03/16 17:13:52 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		res = res * (nb - 1);
		nb--;
	}
	return (res);
}
