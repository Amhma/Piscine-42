#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

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
	t_list	*elem;

	buffer = NULL;
	ft_list_push_back(&buffer, "Salut ");
	ft_list_push_back(&buffer, "comment ");
	ft_list_push_back(&buffer, "tu ");
	ft_list_push_back(&buffer, "vas ");
	ft_list_push_back(&buffer, "bien ");
	ft_list_push_back(&buffer, "!!");

	elem = ft_list_at(buffer, 14);
	if (!elem)
		return (0);
	printf("%s\n", (char *)(elem->data));
	return (0);
}
