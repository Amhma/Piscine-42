/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:47:33 by hzaz              #+#    #+#             */
/*   Updated: 2022/03/24 19:54:30 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "list.h"
# include <stdlib.h>
# include <unistd.h>

void	ft_list_push_back(t_list **begin_list, char c);
void	ft_list_clear(t_list **begin_list);
int		ft_list_size(t_list *begin_list);
int		ft_atoi(char *str);

#endif
