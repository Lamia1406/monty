#include "monty.h"
#include <stdio.h>
/**
 * add -  adds the top two elements of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void add(stack_t **stack, unsigned int line_number)
{
	int count_el = 0;
	stack_t *temp = *stack;
	int result = 0, i;

	while (temp != NULL)
	{
		count_el++;
		temp = temp->next;
	}
	if (count_el < 2)
	{
		too_short_stack("add");
		return;
	}
	for (i = 0; i < 2; i++)
	{
		result += (*stack)->n;
		*stack = (*stack)->next;
	}
	free(temp);
	realloc_memory(result);
	push(stack, line_number);
	(void)line_number;
}
