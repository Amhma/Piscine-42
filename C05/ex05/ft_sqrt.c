/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:01 by amahla            #+#    #+#             */
/*   Updated: 2022/03/17 21:40:35 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int				n;
	unsigned int	res;

	n = 1;
	res = nb;
	if (nb <= 0)
		return (0);
	while (n * n < res)
		n++;
	if (n * n == res)
		return (n);
	return (0);
}
