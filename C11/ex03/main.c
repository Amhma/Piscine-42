#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*));

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
	char *tab[5] = {"YaaO", "biecn", "ou", "baien", "fss"};

	printf("%d\n", ft_count_if(tab, 5, &ft_check_c));
	return (0);
}
