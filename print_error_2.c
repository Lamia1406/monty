#include "monty.h"
/**
 * stack_empty - function that handles errors when a stack is empty
 * @op: the operation done on the stack
 */
void stack_empty(char *op)
{
	fprintf(stderr, "L%u: can't %s an empty stack\n", cmd_file.line_nums, op);
	cmd_file.status = 1;
}
/**
 * too_short_stack - function that handles errors when a stack is
 *				less than a specific number of elements
 * @op: the operation done on the stack
 */
void too_short_stack(char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", cmd_file.line_nums, op);
	cmd_file.status = 1;
}
/**
 * not_ascii - function that handles errors when a char is not in ascii table
 */
void not_ascii(void)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", cmd_file.line_nums);
	cmd_file.status = 1;
}
/**
 * div_zero - function that handles errors when a a specific stack element
 *						is divided by zero
 */
void div_zero(void)
{
	fprintf(stderr, "L%u: division by zero\n", cmd_file.line_nums);
	cmd_file.status = 1;
}
/**
 * stack_empty_2 - function that handles errors when a stack is empty
 * @op: the operation done on the stack
 */
void stack_empty_2(char *op)
{
	fprintf(stderr, "L%u: can't %s, stack empty\n", cmd_file.line_nums, op);
	cmd_file.status = 1;
}
