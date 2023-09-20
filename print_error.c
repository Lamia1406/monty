#include <string.h>
#include "monty.h"
#include <unistd.h>
/**
 * wrong_args_number - function that prints an error message and exits
 *			if the wrong number of arguments is provided.
 */
void wrong_args_number(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	exit(EXIT_FAILURE);
}
/**
 * file_can_t_open - function that prints an error message indicating
 *			a file couldn't be opened and exits.
 * @file: The name of the file that couldn't be opened.
 */
void file_can_t_open(char *file)
{
	write(STDERR_FILENO, "Error: Can't open file ", 23);
	write(STDERR_FILENO, file, strlen(file));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
