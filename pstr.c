#include "monty.h"
#include <stdio.h>
/**
 * pstr - prints the string starting from the top of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
		printf("\n");
	while (node != NULL)
	{
		if (node->n == 0 || (node->n < 0 && node->n > 177))
		{
			free(node);
			printf("\n");
			break;
		}
		printf("%c", node->n);
		node = node->next;
	}
	(void)line_number;
	free(node);
}
