#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees allocated mem
 * @c: structure dog to free
 */
void free_dog(dog_t *c)
{
	if (c)
	{
		free(c->name);
		free(c->owner);
		free(c);
	}
}
