#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	*ft_map(int *tab, int length, int(*f)(int));

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	print_nb(int nb)
{
	return (nb * 0);
}

int	main(void)
{
	int tab[9] = {10, 57, 43, 21, 54, 223, 1023, 86, 40};
	int	*tab1;
	int	i;

	tab1 = ft_map(tab, 9, &print_nb);
	for (i = 0; i < 9; i++)
		printf("%d\n", tab1[i]);
	return (0);
}
