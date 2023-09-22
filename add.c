#include "monty.h"
#include <stdio.h>
/**
 * add -  adds the top two elements of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		too_short_stack("add");
		return;
	}
	result = (*stack)->n + (*stack)->next->n;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->n = result;
	free(temp);
	(void)line_number;
}
