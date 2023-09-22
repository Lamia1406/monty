#include "monty.h"
#include <stdio.h>
/**
 * pchar - prints the char value of the top of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		stack_empty_2("pchar");
		return;
	}
	if (node->n < 0 || node->n > 127)
	{
		not_ascii();
		return;
	}
	printf("%c\n", node->n);
	(void)line_number;
}
