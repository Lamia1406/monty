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

	while (node != NULL)
	{
		if (node->n == 0 || (node->n < 0 && node->n > 127))
			break;
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
	(void)line_number;
	if (*stack != NULL)
		free(node);
}
