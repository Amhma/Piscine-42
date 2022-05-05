#include<stdlib.h>
#include<stdio.h>

int	main(void)
{
	printf("Un char fait %ld octets\n", sizeof(char));
	printf("Un pointeur de char fait %ld octets\n", sizeof(char *));
	printf("Un int fait %ld octets\n", sizeof(int));
	printf("Un long fait %ld octets\n", sizeof(long));
	printf("Un double fait %ld octets\n", sizeof(double));
	return (0);
}
