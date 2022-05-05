/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:11 by amahla            #+#    #+#             */
/*   Updated: 2022/03/18 22:28:11 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	unsigned int	n;
	unsigned int	res;

	n = 3;
	res = nb;
	if (nb < 3)
		return (2);
	if (!(res % 2))
		res++;
	while (n * n <= res)
	{
		if (res % n == 0)
		{
			res += 2;
			n = 1;
		}
		n += 2;
	}
	return ((int)res);
}
