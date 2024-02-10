#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary string to convert.
 *
 * Return: The converted unsigned int if there is no error, otherwise 0.
 */
unsigned int binary_to_uint(const char *b)
{
    int k;
    unsigned int digit;

    digit = 0;
    if (!b)
        return (0);
    for (k = 0; b[k] != '\0'; k++)
    {
        if (b[k] != '0' && b[k] != '1')
            return (0);
    }
    for (k = 0; b[k] != '\0'; k++)
    {
        digit <<= 1;
        if (b[k] == '1')
            digit += 1;
    }
    return (digit);
}

