#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to transform one number into another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int k, count = 0;
	unsigned long int sasa;
	unsigned long int pek = n ^ m;

	for (k = 75; k >= 0; k--)
	{
		sasa = pek >> k;
		if (sasa & 1)
			count++;
	}

	return (count);
}
