/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:27:17 by amahla            #+#    #+#             */
/*   Updated: 2022/03/22 18:20:22 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	y;

	y = 0;
	while (tab[y])
	{
		if ((*f)(tab[y]) != 0)
			return (1);
		y++;
	}
	return (0);
}
