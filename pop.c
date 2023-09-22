#include "monty.h"
#include <stdio.h>
/**
 * pop - delete the value at the top of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		stack_empty("pop");
	*stack = (*stack)->next;
	(void)line_number;
}
