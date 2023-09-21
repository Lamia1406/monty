#include "monty.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/**
* manage_file - function that manages a file input by a user
*/
void manage_file(void)
{
	char buffer[1024], line[1024];
	int i, bytesRead, lineIndex = 0, line_number = 0;

	while ((bytesRead = read(cmd_file.file, buffer, sizeof(buffer))) > 0)
	{
		for (i = 0; i < bytesRead; i++)
		{
			if (buffer[i] != '\n')
			{
				line[lineIndex] = buffer[i];
				lineIndex++;
			}
			else
			{
				line[lineIndex] = '\0';
				cmd_file.line_nums = ++line_number;
				handle_line(line);
				lineIndex = 0;
			}
		}
	}
close(cmd_file.file);
}
