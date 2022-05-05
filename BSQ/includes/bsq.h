/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:47:16 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/30 23:08:05 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			data;
	struct s_list	*next;
}					t_list;

int		ft_atoi(char *str);
int		check_map(char **map, char *info);
int		ft_strlen(char *str);
int		ft_strlen_int(int *tab);
int		ft_strlen_map(char **map);
int		ft_malloc(char ***map, char **info, t_list *buffer, int fd);
void	ft_print_array(char **strs);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_resolve(char **map, char *info, int *res);
void	ft_list_push_back(t_list **begin_list, char c);
void	ft_list_clear(t_list **begin_list);
int		ft_list_size(t_list *begin_list);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_free_map(char **map);
void	ft_free_int(int **map_int, char **map);

#endif
