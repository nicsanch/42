#include "ft_printf.h"

void	ft_leaks(void)
{
	printf("\nLEAKS O.K.!");
	system("leaks -q a.out");
}

int main(void)
{
	int ft_cnt = 0;
	int cnt = 0;
	char c = 'C';
	char *string = "Nico";
	void *ptr = &c;
	int	numero = 123;
	unsigned int unum = 54321;

	cnt = printf("\nChecking...\nChar: %c. String: %s. Number: %i. Unsigned number: %u Number in tens: %d. Number in base hex: %x. Number in base HEX: %X. Pointer address: %p. Passed 100%%\n", c, string, numero, unum, numero, numero, numero, ptr);
	ft_cnt = ft_printf("\nChecking...\nChar: %c. String: %s. Number: %i. Unsigned number: %u Number in tens: %d. Number in base hex: %x. Number in base HEX: %X. Pointer address: %p. Passed 100%%\n", c, string, numero, unum, numero, numero, numero, ptr);
    printf("\nVALUE of ft_printf: 	  %i" , ft_cnt);
    printf("\nVALUE of original printf: %i\n\n" , cnt);
	atexit(ft_leaks);
    return 0;
}
