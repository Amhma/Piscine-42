#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*(str + i)) 
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    int     i;  
    char    *str_cp;

    i = 0;
    str_cp = malloc((ft_strlen(src) + 1) * sizeof(char));
    if (!str_cp)
        return (NULL);
    if (*(src + i)) 
    {   
        while (*(src + i)) 
        {
            *(str_cp + i) = *(src + i); 
            i++;
        }
        *(str_cp + i) = '\0';
    }   
    return (str_cp);
}

void	free_data(void *data)
{
	free(data);
}

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
	t_list	*elem;

	buffer = NULL;
	ft_list_push_back(&buffer, ft_strdup("Salut "));
	ft_list_push_back(&buffer, ft_strdup("comment "));
	ft_list_push_back(&buffer, ft_strdup("tu "));
	ft_list_push_back(&buffer, ft_strdup("vas "));
	ft_list_push_back(&buffer, ft_strdup("bien "));
	ft_list_push_back(&buffer, ft_strdup("!!"));
	ft_list_push_back(&buffer, ft_strdup("Salut "));

	ft_list_remove_if(&buffer, "Salut ", &ft_strcmp, &free_data);

	elem = buffer;
	while (elem)
	{
		printf("%s\n", (char *)(elem->data));
		elem = elem->next;
	}
	return (0);
}
