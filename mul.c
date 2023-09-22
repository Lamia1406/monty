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
	int count_el = 0;
	stack_t *temp = *stack;
	int result = 0;

	if (*stack == NULL)
		stack_empty("mul");
	while (temp != NULL)
	{
		count_el++;
		temp = temp->next;
	}
	free(temp);
	if (count_el < 2)
		too_short_stack("mul");
	result = (*stack)->n;
	(*stack) = (*stack)->next;
	result *= (*stack)->n;
	(*stack) = (*stack)->next;
	realloc_memory(result);
	push(stack, line_number);
	(void)line_number;
}
