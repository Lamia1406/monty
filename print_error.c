#include <string.h>
#include "monty.h"
#include <unistd.h>
/**
 * wrong_args_number - function that prints an error message and exits
 *			if the wrong number of arguments is provided.
 */
void wrong_args_number(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * file_can_t_open - function that prints an error message indicating
 *			a file couldn't be opened and exits.
 * @file: The name of the file that couldn't be opened.
 */
void file_can_t_open(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * uknown_opcode - function that handles unknown opcodes
 *			encountered during execution.
 * @opcode: The unknown opcode encountered.
 */
void uknown_opcode(char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", cmd_file.line_nums, opcode);
	exit(EXIT_FAILURE);
}
/**
 * malloc_failed - function that handles a failed memory allocation (malloc).
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * not_int - function that handles errors when a non-integer is expected.
 */
void not_int(void)
{
	fprintf(stderr, "L%u: usage: push integer\n", cmd_file.line_nums);
	cmd_file.status = 1;
}
