/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:22 by amahla            #+#    #+#             */
/*   Updated: 2022/03/12 16:16:34 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alphanumeric(char c)
{
	if (!(c >= 'a' && c <= 'z'))
	{
		if (!(c >= 'A' && c <= 'Z'))
		{
			if (!(c >= '0' && c <= '9'))
				return (0);
		}
	}
	return (1);
}

int	ft_char_is_lowercase(char c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

int	ft_char_is_uppercase(char c)
{
	if (!(c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

void	ft_char_up_or_low_case(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	else
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
	{
		if ((ft_char_is_lowercase(str[i]) && i == 0)
			|| (i > 0 && !ft_char_is_alphanumeric(str[i - 1])
				&& ft_char_is_lowercase(str[i])))
			ft_char_up_or_low_case(str + i);
		else if (ft_char_is_alphanumeric(str[i - 1])
			&& ft_char_is_alphanumeric(str[i])
			&& ft_char_is_uppercase(str[i]))
			ft_char_up_or_low_case(str + i);
		i++;
	}
	return (str);
}
