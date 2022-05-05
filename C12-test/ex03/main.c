#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

t_list	*ft_list_last(t_list *begin_list);

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
	t_list	*elem;

	buffer = NULL;
	ft_push_back(&buffer, "Salut ");
	ft_push_back(&buffer, "comment ");
	ft_push_back(&buffer, "tu ");
	ft_push_back(&buffer, "vas ");
	ft_push_back(&buffer, "bien ");
	ft_push_back(&buffer, "!!");

	elem = ft_list_last(buffer);
	
	printf("%s\n", (char *)(elem->data));
	return (0);
}
