#include "lists.h"
/**
 * print_list - Prints the elements contained in a listt.
 * @h: list.
 *
 * Return: number.
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (q)
	{
		if (q->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", q->len, q->str);
		q = q->next;
		i++;
	}
	return (i);
}

