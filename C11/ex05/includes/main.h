/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:54:13 by amahla            #+#    #+#             */
/*   Updated: 2022/03/23 15:48:22 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	(*ft_calculator(char c))(int a, int b);

#endif
