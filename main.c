#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * main -Entry point of the program
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: 0(Success)
 */
int main(int argc, char **argv)
{
	int file;
	stack_t *head = NULL;

	if (argc != 2)
		wrong_args_number();
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		file_can_t_open(argv[1]);
	cmd_file.file = file;
	cmd_file.head = &head;
	manage_file();
	return (0);
}
