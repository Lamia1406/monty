#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct file_details - Structure to hold file details.
 * @file: The file identifier.
 * @line_nums: the number of the line containing the command.
 * @head: A pointer to a stack of stack_t pointers.
 * @params: the arguments following a command.
 * @status: code status number (1 in case of failure)
 */
typedef struct file_details
{
	int file;
	int line_nums;
	stack_t **head;
	char **params;
	int status;
} file_t;

extern file_t cmd_file;
file_t cmd_file;
/* file Manipulation */
void manage_file(void);
void handle_line(char *line);
char **separate_params(char *input);
void handle_command(char *cmd, char **params);
int check_line_empty(char *input);
void copy_non_space_strings(char **argv, char **params, char *token);
/* Commands */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
/* Error Handling */
void wrong_args_number(void);
void file_can_t_open(char *file);
void uknown_opcode(char *opcode);
void malloc_failed(void);
void not_int(void);
void stack_empty(char *op);
void too_short_stack(char *op);
void not_ascii(void);
void div_zero(void);
void pchar_stack_empty(void);
/* Free Memory */
void free_double_pointer(char **ptr, int length);
void free_stack(stack_t **head);
/* string <-> int Manipulation */
int countDigits(int num);
void realloc_memory(int element);
int isnumber(char *string_num);
#endif
