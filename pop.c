#include "monty.h"
#include <stdio.h>
/**
 * pop - delete the value at the top of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		stack_empty("pop");
		return;
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
	(void)line_number;
}
