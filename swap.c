#include "monty.h"
#include <stdio.h>
/**
 * swap - swaps the top two elements of the stack
 * @stack: A pointer to the pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where the push
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int element, count_el = 0;
	stack_t *temp = *stack;

	if (*stack == NULL)
		stack_empty();
	while (temp != NULL)
	{
		count_el++;
		temp = temp->next;
	}
	if (count_el < 2)
		too_short_stack();
	temp = (*stack)->next;
	element = temp->n;
	(*stack)->next = temp->next;
	free(temp);
	realloc_memory(element);
	push(stack, line_number);
	(void)line_number;
}
/**
 * countDigits - Count the number of digits in an integer.
 *@num: The integer to count the digits of.
 * Return: The number of digits in the given integer.
 */
int countDigits(int num)
{
	int count = 0;

	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
/**
 * realloc_memory - Reallocate memory for a parameter and
 *					convert an integer to a string.
 * @element: The integer value to be converted and stored as a string.
 */
void realloc_memory(int element)
{
	int count = countDigits(element);
	char *new_param = realloc(cmd_file.params[1], count + 1);

	if (new_param == NULL)
		malloc_failed();
	sprintf(new_param, "%d", element);
	cmd_file.params[1] = new_param;
}
