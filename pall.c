#include "monty.h"
#include <stdio.h>
/**
 * pall - prints all the values on the stack
 *		starting from the top of the stack.
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
