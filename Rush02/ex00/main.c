/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:06:28 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 20:26:55 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush.h"

char	*ft_trim(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	return (str);
}

int	parsing(char *buffer, t_list **dico)
{
	char	*number;
	char	*letter;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!check_line(buffer))
		return (0);
	buffer = ft_trim(buffer);
	while (buffer[i] == ' ' || (buffer[i] >= 9 && buffer[i] <= 13)
		|| buffer[i] == '+' || buffer[i] == '-')
		buffer++;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	number = ft_strdup(buffer, i);
	while (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == ':')
		i++;
	while (buffer[i + j])
		j++;
	letter = ft_strdup(buffer + i, j);
	ft_list_push_back(dico, number, letter);
	return (1);
}

int	load_file(char *file, t_list **dico)
{
	char	buffer[2048];
	int		rd;
	int		fd;
	int		index;

	index = 0;
	rd = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (rd > 0)
	{
		rd = read(fd, buffer + index, 1);
		if (buffer[index] == '\n' || rd == 0)
		{
			buffer[index] = '\0';
			parsing(buffer, dico);
			index = 0;
		}
		else
			index++;
	}
	if (rd == -1 || close(fd) == -1)
		return (0);
	return (1);
}

int	process(char *file, char *number)
{
	t_list		*dico;
	t_result	*final;

	dico = NULL;
	final = NULL;
	if (!load_file(file, &dico))
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	if (!ft_check_number(number, dico))
		return (0);
	final = ft_conversion(number, dico);
	if (!final)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	ft_putlist(final);
	ft_remove(&dico, &final);
	return (1);
}

int	main(int ac, char **av)
{
	char		*file;
	char		*number;

	if (ac >= 2 && ac <= 3)
	{
		if (ac == 2)
		{
			file = "numbers.dict";
			number = av[1];
		}
		else if (ac == 3)
		{
			file = av[1];
			number = av[2];
		}
		process(file, number);
	}
	else
		write(2, "Wrong number of arguments\nPlease retry...\n", 42);
	return (0);
}	
