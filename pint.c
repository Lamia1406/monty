#include "monty.h"
#include <stdio.h>
/**
 * pint - prints the value at the top of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
		stack_empty("pint");
	printf("%d\n", node->n);
	(void)line_number;
}
