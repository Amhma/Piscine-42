#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

t_list	*ft_create_elem(void *data);

void    ft_list_push_front(t_list **begin_list, void *data);

void	ft_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = *begin_list;
	if (!elem)
		*begin_list = ft_create_elem(data);
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
}

int	main(void)
{
	t_list *buffer;

	buffer = NULL;
	ft_push_back(&buffer, "Salut ");
	ft_push_back(&buffer, "comment ");
	ft_push_back(&buffer, "tu ");
	ft_push_back(&buffer, "vas ");
	ft_push_back(&buffer, "bien ");
	ft_push_back(&buffer, "!!");
	ft_list_push_front(&buffer, "avant");
	ft_list_push_front(&buffer, "ca");
	ft_list_push_front(&buffer, "mis");
	ft_list_push_front(&buffer, "J'ai");

	while (buffer)
	{
		printf("%s\n", (char *)(buffer->data));
		buffer = buffer->next;
	}
	return (0);
}
