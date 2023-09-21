#include <string.h>
#include "monty.h"
/**
 * handle_line - function that processes a line of input.
 * @line :pointer to the input line to be processed.
 */
void handle_line(char *line)
{
	char **params, **tags;
	int i, j;

	if (check_line_empty(line) == 1)
		return;
	params = separate_params(line);
	for (i = 0; params[i] != NULL; i++)
		;
	tags = malloc(sizeof(char *) * i);
	if (tags == NULL)
	{
		for (i = 0; params[i] != NULL; i++)
			free(params[i]);
		free(params);
		malloc_failed();
	}
	for (j = 0; j < i - 1 ; j++)
	{
		tags[j] = malloc(strlen(params[j + 1]) + 1);
		if (tags[j] == NULL)
		{
			for (i = 0; params[i] != NULL; i++)
				free(params[i]);
			free(params);
			free_double_pointer(tags, j);
			malloc_failed();
		}
		strcpy(tags[j], params[j + 1]);
	}
	tags[j] = NULL;
	handle_command(params[0], params);
	free_double_pointer(params, i);
	free_double_pointer(tags, i - 1);
}
/**
 * separate_params - function that retrieves all the params from the input
 * @input: user input
 * Return: char double array of params
*/
char **separate_params(char *input)
{
	char **tokens, *one_param, *temp_input;
	int i = 0;

	strtok(input, "\n");
	temp_input = malloc(strlen(input) + 1);
	if (temp_input == NULL)
		malloc_failed();
	strcpy(temp_input, input);
	tokens = (char **) malloc(sizeof(char *) * (3));
	if (tokens == NULL)
	{
		free(temp_input);
		malloc_failed();
	}
	one_param = strtok(input, " \t");
	i = 0;
	while (one_param != NULL)
	{
		tokens[i] = malloc(sizeof(strlen(one_param) + 1));
		if (tokens[i] == NULL)
			malloc_failed();
		strcpy(tokens[i], one_param);
		one_param = strtok(NULL, " \t");
		i++;
		if (i == 2)
			break;
	}
	tokens[i] = NULL;
	free(temp_input);
	return (tokens);
}
/**
 * handle_command - function that processes a function based on a command
 * @cmd: the command
 * @params: the arguments following the command
*/
void handle_command(char *cmd, char **params)
{
	int j;
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
	};
	int nb_commands = sizeof(commands) / sizeof(commands[0]);

	cmd_file.params = params;
	for (j = 0; j < nb_commands; j++)
	{
		if (strcmp(cmd, commands[j].opcode) == 0)
		{
			commands[j].f(cmd_file.head, cmd_file.line_nums);
			return;
		}
	}
	if (strcmp(cmd, "nop") != 0)
		uknown_opcode(cmd);
}
