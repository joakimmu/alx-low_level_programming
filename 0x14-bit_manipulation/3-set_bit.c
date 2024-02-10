/* set_bit.c */

#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: Pointer to the number whose bit needs to be set
 * @index: Index of the bit to set, starting from 0
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8) /* Check if index is out of bounds */
        return -1;

    *n |= (1UL << index); /* Set the bit at the given index */

    return 1;
}

