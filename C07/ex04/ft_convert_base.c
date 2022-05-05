/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:06:19 by amahla            #+#    #+#             */
/*   Updated: 2022/03/21 11:22:02 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str);
int	ft_check_base(char *str);
int	ft_atoi_base(char *str, char *base);

int	nb_len(long long nb, int len_base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		nb /= len_base;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base, char *str, int i)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		str[0] = '-';
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= (unsigned int)ft_strlen(base))
		ft_putnbr_base(nb / ft_strlen(base), base, str, i - 1);
	str[i] = base[nb % ft_strlen(base)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*convert_nb;
	int		nb;
	int		size_array;

	size_array = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
		size_array++;
	size_array = size_array + nb_len((long long)nb, ft_strlen(base_to));
	convert_nb = malloc((size_array + 1) * sizeof(char));
	if (!convert_nb)
		return (NULL);
	convert_nb[size_array] = '\0';
	ft_putnbr_base(nb, base_to, convert_nb, size_array - 1);
	return (convert_nb);
}
