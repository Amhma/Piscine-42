#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	ft_any(char **tab, int(*f)(char*));

int	ft_check_c(char *str)
{
	int	i;
	
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == 'c')
			return (1);
		if (*(str + i) == 'a')
			return (-1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char *tab[5] = {"YcO", "bien", "ou", "bien", NULL};

	printf("%d\n", ft_any(tab, &ft_check_c));
	return (0);
}
