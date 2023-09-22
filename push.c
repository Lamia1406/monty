#include "monty.h"
#include <stdio.h>
#include <ctype.h>
/**
 * push - Pushes an integer onto the stack.
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *node;

	(void)line_number;

	if (cmd_file.params[0] == NULL || isnumber(cmd_file.params[0]) == 1)
	{
		not_int();
		return;
	}
	n = atoi(cmd_file.params[0]);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_failed();
	node->n = n;
	if (*stack != NULL)
	{
		node->next = *stack;
	}
	else
	{
		node->next = NULL;
	}
	*stack = node;
}
/**
 * isnumber - checks if a string is convertible to a number or not
 * @string_num: the string to check
 * Return: 0 if True and 1 if False
 */
int isnumber(char *string_num)
{
	int i;

	for  (i = 0; string_num[i]; i++)
	{
		if (string_num[i] != '-' && isdigit(string_num[i]) == 0)
			return (1);
	}
	return (0);
}
