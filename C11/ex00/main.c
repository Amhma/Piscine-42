#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void	ft_foreach(int *tab, int length, void(*f)(int));

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

void	print_nb(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}

int	main(void)
{
	int tab[9] = {10, 57, 43, 21, 54, 223, 1023, 86, 40};

	ft_foreach(tab, 9, &print_nb);
	return (0);
}
