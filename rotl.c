#include "monty.h"
#include <stdio.h>
/**
 * rotl -  rotates the stack to the top.
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int temp;

	if (*stack == NULL)
		return;
	node = *stack;
	temp = node->n;
	while (node->next != NULL)
	{
		node->n = node->next->n;
		node = node->next;
	}
	node->n = temp;
	(void)line_number;
}
