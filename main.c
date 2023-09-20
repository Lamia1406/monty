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
	FILE *file;

	if (argc != 2)
		wrong_args_number();
	if (open(argv[1], O_RDONLY) == -1)
		file_can_t_open(argv[1]);
	return (0);
}
