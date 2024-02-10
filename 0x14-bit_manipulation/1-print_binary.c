#include "main.h"

/**
 * expo - calculates the result of raising a number to an exponential
 * @number: the number of the exponent
 * @exponential: raised to
 *
 * Return: the result of number raised to the exponential
 */
unsigned long int expo(unsigned int number, unsigned int exponential)
{
    unsigned long int result = 1;
    unsigned int i;

    for (i = 0; i < exponential; i++)
        result *= number;

    return result;
}

void print_binary(unsigned long int n)
{
    unsigned long int split, confirm;
    char list;

    list = 0;
    split = expo(2, (sizeof(unsigned long int) * 8) - 1);
    while (split != 0)
    {
        confirm = n & split;
        if (confirm == split)
        {
            list = 1;
            _putchar('1');
        }
        else if (list == 1 || split == 1)
        {
            _putchar('0');
        }
        split >>= 1;
    }
}

