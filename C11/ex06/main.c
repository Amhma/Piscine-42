#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void	ft_sort_string_tab(char **tab);

int	ft_check(int a, int b)
{
	if (a < b)
		return (-1);
	if (a == b)
		return (0);
	return (1);
}

int	main(void)
{
	int	y = 0;

	char *tab[5] = {"aello", "Aomment", "8as", "Hhhhh", NULL};

	ft_sort_string_tab(tab);
	while (tab[y])
	{
		printf("%s\n", tab[y]);
		y++;
	}
	return (0);
}
