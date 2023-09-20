#include "monty.h"
/**
 * free_double_pointer - Frees memory allocated for
 *                              a double pointer and its content.
 * @ptr: The double pointer to be freed.
 * @length: The length of the array of pointers.
 */
void free_double_pointer(char **ptr, int length)
{
	int j;

	for (j = 0; j < length; j++)
		free(ptr[j]);
	free(ptr);
}
