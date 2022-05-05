/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:47:13 by amahla            #+#    #+#             */
/*   Updated: 2022/03/17 22:51:09 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	n;
	unsigned int	res;

	res = nb;
	n = 3;
	if (res == 2)
		return (1);
	if (nb < 3 || !(res % 2))
		return (0);
	while (n * n <= res)
	{
		if (res % n == 0)
			return (0);
		n += 2;
	}
	return (1);
}
