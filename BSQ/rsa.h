/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:45:33 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/28 19:05:09 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSA_H
# define RSA_H

# include <fcntl.h>
# include "list.h"
# include <unistd.h>

int	ft_malloc(char ***map, char **info, t_list *buffer, int fd);
void	ft_print_array(char **strs, int size);
int		ft_atoi(char *str);
int	ft_strlen(char *str);
void    ft_resolve(char **map, char *info, int *res);

#endif
