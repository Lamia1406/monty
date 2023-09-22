#include "monty.h"
#include <stdio.h>
/**
 * _mul -  mul the second top element of the stack with
 *				the top element of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		too_short_stack("mul");
		return;
	}
	result = (*stack)->n * (*stack)->next->n;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->n = result;
	free(temp);
	(void)line_number;
}
