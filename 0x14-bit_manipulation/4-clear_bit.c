#include "main.h"

/**
 * clear_bit - Clears a bit at a given index.
 * @n: Pointer to the number whose bit to clear.
 * @index: The index of the bit to clear.
 *
 * Return: 1 if it works or -1 if it fails.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int mask;

    if (index >= sizeof(unsigned long int) * 8) 
        return -1;

    mask = (unsigned long int)1 << index; 
    *n &= ~mask; 

    return 1; 
}

