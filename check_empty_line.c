#include "monty.h"
/**
 * check_line_empty - Checks if a string consists of only whitespace characters
 * @input: The input string to be checked
 *
 * Return: 1 if the string contains only whitespace characters, 0 otherwise
 */
int check_line_empty(char *input)
{
	int empty_spaces = 1;
	int i;

	if (input[0] == '#')
		return (empty_spaces);
	for (i = 0; input[i] ; i++)
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			empty_spaces = 0;
			break;
		}
	}
	return (empty_spaces);
}
