#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: names tobe  printed
 * @b: the pointer to the printing function
 */
void print_name(char *name, void (*b)(char *))
{
	if (!name || !b)
		return;
	f(name);
}
