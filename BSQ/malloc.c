/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:46:36 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/24 22:32:28 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"malloc.h"


int	ft_malloc_uni(char **str, t_list **buffer, int y)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = *buffer;
	str[y] = malloc((ft_list_size(elem) + 1) * sizeof(char));
	if (!*str)
		return (0);
	while (elem)
	{
		*(str[y] + i) = elem->data;
		elem = elem->next;
		i++;
	}
	*(str[y] + i) = '\0';
	ft_list_clear(buffer);
	return (1);
}

int	ft_malloc_multi(char ***str, int size)
{
	*str = malloc((size + 1) * sizeof(char *));
	if (!*str)
		return (0);
	return (1);
}

int	ft_malloc(char ***map, char **info, t_list *buffer, int fd)
{
	int		i;
	int		rd;
	char	buf;

	i = -1;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, &buf, 1);
		if (rd > 0 && buf != '\n')
			ft_list_push_back(&buffer, buf); 
	 	if ((rd == 0 || buf == '\n') && i < 0)
		{
			if (!ft_malloc_uni(info, &buffer, 0) || !ft_atoi(*info))
				return (0);
			if (!ft_malloc_multi(map, ft_atoi(*info)))
				return (0);
			i++;
		}
		else if ((rd == 0 || buf == '\n') && i < ft_atoi(*info))
		{
			if (!ft_malloc_uni(*map, &buffer, i))
				return (0);
			i++;
		}
		else if (rd == 0 || i == ft_atoi(*info))
			*(map[0] + i) = NULL;
	}
	return (1);
}

void	ft_print_array(char **strs, int size)
{
	int	y;
	int	x;

	y = 0;
	while (strs[y])
	{
		x = 0;
		while (*(strs[y] + x))
		{
			write(1, strs[y] + x, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
