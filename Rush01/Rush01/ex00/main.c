/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:06:06 by amahla            #+#    #+#             */
/*   Updated: 2022/03/19 17:58:04 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

void	ft_init_array(char **strs);
void	ft_print_array(char **strs);
void	ft_split(char **strs, char *arg);
int		ft_backtracking(char **view, char **solution, int pos);
int		ft_check_error(char **solution);

int	ft_is_arg_valid(char *arg)
{
	int	i;
	int	nb_view;

	i = 0;
	nb_view = 0;
	while (*(arg + i))
	{
		if (*(arg + i) >= '1' && *(arg + i) <= '4')
			nb_view++;
		else if (nb_view > 15 && *(arg + i) == ' ')
			return (0);
		else if (i % 2 == 0 && !(*(arg + i) >= '1' && *(arg + i) <= '4'))
			return (0);
		else if (i % 2 == 1 && *(arg + i) != ' ')
			return (0);
		i++;
	}
	if (nb_view != 16)
		return (0);
	return (1);
}

char	**ft_malloc_array(char **strs)
{
	int	y;

	y = 0;
	strs = malloc(5 * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[4] = NULL;
	while (y < 4)
	{
		strs[y] = malloc(5 * sizeof(char));
		if (!strs[y])
			return (NULL);
		*(strs[y] + 4) = '\0';
		y++;
	}
	return (strs);
}

void	ft_free_array(char **strs1, char **strs2)
{
	int	y;

	y = 0;
	while (y < 4)
	{
		free(strs1[y]);
		free(strs2[y]);
		y++;
	}
	free(strs1);
	free(strs2);
}

int	main(int ac, char **av)
{
	char	**view;
	char	**solution;

	view = NULL;
	solution = NULL;
	view = ft_malloc_array(view);
	solution = ft_malloc_array(solution);
	if (ac != 2 || !view || !solution || !ft_is_arg_valid(av[1]))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_init_array(solution);
	ft_split(view, av[1]);
	ft_backtracking(view, solution, 0);
	if (!ft_check_error(solution))
	{
		ft_free_array(view, solution);
		return (0);
	}
	ft_print_array(solution);
	ft_free_array(view, solution);
	return (0);
}
