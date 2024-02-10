#include "main.h"
#include <stddef.h>

/**
 * get_bit - gives bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to extract.
 *
 * Return: bit value at index or -1 if there is an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
    unsigned long int mask;

    if (index >= sizeof(unsigned long int) * 8)
        return -1;

    mask = (unsigned long int)1 << index;
    if (n & mask)
        return 1;
    else
        return 0;
}

