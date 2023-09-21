#include "monty.h"
/**
 * stack_empty - function that handles errors when a stack is empty
 */
void stack_empty(void)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", cmd_file.line_nums);
	exit(EXIT_FAILURE);
}
/**
 * too_short_stack - function that handles errors when a stack is
 *				less than a specific number of elements
 */
void too_short_stack(void)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", cmd_file.line_nums);
	exit(EXIT_FAILURE);
}
