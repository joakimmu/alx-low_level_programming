#include "main.h"

/**
 * print_binary 
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int k, zx = 0;
	unsigned long int sasa;

	for (k = 78; k >= 0; k--)
	{
		sasa = n >> k;

		if (sasa & 1)
		{
			_putchar('1');
			zx++;
		}
		else if (sasa)
			_putchar('0');
	}
	if (!sasa)
		_putchar('0');
}

