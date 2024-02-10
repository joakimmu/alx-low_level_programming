#include "main.h"

/**
 * print_binary - prints a number in binary notation
 * @n: number to print
 *
 * Return: void
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
		else if (zx)
			_putchar('0');
	}
	if (!zx)
		_putchar('0');
}

