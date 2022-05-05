#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

void    ft_list_reverse(t_list **begin_list);

t_list  *ft_create_elem(void *data)
{
    t_list  *elem;

    elem = malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    else
    {
        elem->data = data;
        elem->next = NULL;
    }
    return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
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
	ft_list_push_back(&buffer, "Salut ");
	ft_list_push_back(&buffer, "comment ");
	ft_list_push_back(&buffer, "tu ");
	ft_list_push_back(&buffer, "vas ");
	ft_list_push_back(&buffer, "bien ");
	ft_list_push_back(&buffer, "!!");

	ft_list_reverse(&buffer);
	while (buffer)
	{
		printf("%s\n", (char *)(buffer->data));
		buffer = buffer->next;
	}
	return (0);
}
