#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

void	ft_putstr(void *data)
{
	int		i;
	char	*str;

	str = (char *)data;
	i = 0;
	while (*(str + i))
		write(1, str + i++, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

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
	t_list	*buffer;
	t_list	*buffer2;
	t_list	*elem;

	buffer = NULL;
	buffer2 = NULL;
	ft_list_push_back(&buffer, "9");
	ft_list_push_back(&buffer, ":");
	ft_list_push_back(&buffer, "5");
	ft_list_push_back(&buffer, "A");
	ft_list_push_back(&buffer, "2");
	ft_list_push_back(&buffer, "1");
	ft_list_push_back(&buffer2, "a");
	ft_list_push_back(&buffer2, "F");
	ft_list_push_back(&buffer2, "4");
	ft_list_push_back(&buffer2, "z");
	ft_list_push_back(&buffer2, "3");
	ft_list_push_back(&buffer2, "m");

	ft_sorted_list_merge(&buffer, buffer2, &ft_strcmp);
	elem = buffer;
	while (elem)
	{
		printf("%s\n", (char *)(elem->data));
		elem = elem->next;
	}
	return (0);
}
