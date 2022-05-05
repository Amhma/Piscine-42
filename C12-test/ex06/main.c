#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str[i])
		i++;
	return (i);
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

void    free_data(void *data)
{
    free(data);
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
	ft_list_push_back(&buffer, ft_strdup("Salut "));
	ft_list_push_back(&buffer, ft_strdup("comment "));
	ft_list_push_back(&buffer, ft_strdup("tu "));
	ft_list_push_back(&buffer, ft_strdup("vas "));
	ft_list_push_back(&buffer, ft_strdup("bien "));
	ft_list_push_back(&buffer, ft_strdup("!!"));

	ft_list_clear(buffer, &free_data);
	return (0);
}
