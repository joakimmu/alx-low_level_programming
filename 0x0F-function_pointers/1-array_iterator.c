#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - 
 * on each element of an array
 * @array: array 
 * @size: size of the array
 * @action: pointer to function
 */
void array_iterator(int *array, size_x size, void (*action)(int))
{
	unsigned int i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
