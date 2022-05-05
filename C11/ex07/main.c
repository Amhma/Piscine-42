#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

int ft_strcmp(char *s1, char *s2)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (*(s1 + i) || *(s2 + i)) 
    {   
        if (*(s1 + i) != *(s2 + i)) 
        {
            res = *(s1 + i) - *(s2 + i); 
        return (res);
        }
        i++;
    }   
    return (0);
}

int	main(void)
{
	int	y = 0;

	char *tab[5] = {"aello", "Aomment", "8as", "Hhhhh", NULL};

	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	while (tab[y])
	{
		printf("%s\n", tab[y]);
		y++;
	}
	return (0);
}
