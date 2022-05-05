/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:27:49 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 18:05:31 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			res = *(s1 + i) - *(s2 + i);
			return (res);
		}
		i++;
	}
	return (0);
}

int	ft_strslen(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
		y++;
	return (y);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		size;
	char	*temp;

	i = 0;
	size = ft_strslen(tab);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
