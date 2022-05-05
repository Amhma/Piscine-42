/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:10:48 by amahla            #+#    #+#             */
/*   Updated: 2022/03/27 19:34:15 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*number;
	char			*letter;
	struct s_list	*next;
}				t_list;

typedef struct s_result
{
	char			*res;
	struct s_result	*next;
}				t_result;

t_result	*ft_conversion(char *nb, t_list *dico);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			ft_strlen1(char *str, int i);
char		*ft_strdup(char *src, int size);
char		*ft_strdup_cat(char **dest, char *src, int size);
void		ft_list_push_back(t_list **begin_list, char *number, char *letter);
void		ft_list_push_back2(t_result **begin_list, char *result);
void		ft_remove_list(t_list **begin_list);
int			ft_thousand(char *str, t_result **final, t_list *dico);
int			ft_unity(char c, t_result **final, t_list *dico);
int			ft_tens(char *str, int *i, t_result **final, t_list *dico);
int			ft_hundred(char c, t_result **final, t_list *dico);
int			check_line(char *str);
int			ft_check_number(char *number, t_list *dico);
int			check_zero(char *str);
void		ft_remove(t_list **begin_list1, t_result **begin_list2);
void		ft_putlist(t_result *begin_list);

#endif
