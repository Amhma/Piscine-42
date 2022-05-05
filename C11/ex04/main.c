#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

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
	int tab[6] = {90, 70, 50, 45, 45, 1};

	printf("%d\n", ft_is_sort(tab, 6, &ft_check));
	return (0);
}
