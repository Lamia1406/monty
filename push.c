#include "monty.h"
#include <stdio.h>
/**
 * push - Pushes an integer onto the stack.
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
		malloc_failed();
	(void)line_number;
	if (cmd_file.params == NULL || cmd_file.params[0] == NULL)
		not_int();
	n = atoi(cmd_file.params[1]);
	if (cmd_file.params[1][0] != '0' && n == 0)
		not_int();
	node->n = n;
	node->next = NULL;
	if (*stack == NULL)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		stack_t *current = *stack;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
		node->prev = current;
	}
}
