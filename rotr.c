#include "monty.h"
#include <stdio.h>
/**
 * rotr -  rotates the stack to the bottom.
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	stack_t *temp_n;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	node = *stack;
	while (node->next != NULL)
	{
		temp_n = node;
		node = node->next;
	}
	temp_n->next = NULL;
	node->next = *stack;
	*stack = node;
	(void)line_number;
}
