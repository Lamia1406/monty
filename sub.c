#include "monty.h"
#include <stdio.h>
/**
 * sub -  subtracts the top element of the stack from the second
 *					top element of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		too_short_stack("sub");
		return;
	}
	result = (*stack)->next->n - (*stack)->n;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->n = result;
	free(temp);
	(void)line_number;
}
