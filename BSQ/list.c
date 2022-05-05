#include"list.h"
#include<stdlib.h>

t_list	*ft_create_elem(char c)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = c;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, char c)
{
	t_list	*elem;

	elem = *begin_list;
	if (!elem)
		*begin_list = ft_create_elem(c);
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(c);
	}
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*elem;

	elem = NULL;
	while (*begin_list)
	{
		elem = *begin_list;
		*begin_list = (*begin_list)->next;
		free(elem);
	}
	*begin_list = NULL;
}

int	ft_list_size(t_list *begin_list)
{
	int	cpt;

	cpt = 0;
	while (begin_list)
	{
		cpt++;
		begin_list = begin_list->next;
	}
	return (cpt);
}
