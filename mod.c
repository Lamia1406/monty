#include "monty.h"
#include <stdio.h>
/**
 * _mod -  computes the rest of the division of  the second top element
 *				of the stack by the top element of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int count_el = 0;
	stack_t *temp = *stack;
	int result = 0;

	if (*stack == NULL)
		stack_empty("mod");
	while (temp != NULL)
	{
		count_el++;
		temp = temp->next;
	}
	free(temp);
	if (count_el < 2)
		too_short_stack("mod");
	if ((*stack)->n == 0)
		div_zero();
	result = (*stack)->n;
	(*stack) = (*stack)->next;
	result = (*stack)->n % result;
	(*stack) = (*stack)->next;
	realloc_memory(result);
	push(stack, line_number);
	(void)line_number;
}
