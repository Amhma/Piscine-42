/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:03:46 by amahla            #+#    #+#             */
/*   Updated: 2022/03/21 11:38:13 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str || ft_strlen(str) <= 1)
		return (0);
	while (*(str + i))
	{
		if (*str == '+' || *str == '-' || (*str >= 9 && *str <= 13))
			return (0);
		j = i + 1;
		while (*(str + j))
		{
			if (str[j] == '+' || str[j] == '-'
				|| (str[j] >= 9 && str[j] <= 13))
				return (0);
			if (*(str + i) == *(str + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_index_char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == c)
			break ;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	if (str)
	{
		while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == ' ')
			i++;
		while (*(str + i) == '+' || *(str + i) == '-')
		{
			if (*(str + i) == '-')
				sign *= -1;
			i++;
		}
		while (ft_is_base(*(str + i), base))
		{
			nb = nb * ft_strlen(base) + ft_index_char_in_base(str[i], base);
			i++;
		}
	}
	return (nb * sign);
}
