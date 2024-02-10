#include "main.h"

/**
 * raise- calculates the result of raising a number to an exponential
 * @natu the number of the exponent
 * @expo: raised to
 *
 * Return: value of (natu ^ expo)
 */
unsigned long int _pow(unsigned int natu, unsigned int expo)
{
	unsigned long int siju;
	unsigned int k;

	siju = 1;
	for (k = 1; k <= expo; k++)
		siju *= natu;
	return (siju);
}


void print_binary(unsigned long int n)
{
	unsigned long int gawa, gawa_2;
	char gawa_3;

	gawa_3 = 0;
	gawa = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (gawa != 0)
	{
		gawa_2 = n & gawa;
		if (gawa_2 == gawa)
		{
			gawa_3 = 1;
			_putchar('1');
		}
		else if (gawa_3 == 1 || gawa == 1)
		{
			_putchar('0');
		}
		gawa >>= 1;
	}
}

