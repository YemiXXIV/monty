#include "monty.h"

/**
 * process_opcode - Process the operation codes in the given file
 * @line: Pointer to the line of operation codes to be processed
 * @stack: Double pointer to the stack
 * @line_number: Line number in the monty bytecode file
 *
 * Return: None
 */

void process_opcode(char *line, stack_t **stack, unsigned int line_number)
{
	char *cmd = strtok(line, " \t\n");

	if (cmd != NULL)
	{
		if (strcmp(cmd, "push") == 0)
		{
			process_push(stack, line_number);
		}
		else if (strcmp(cmd, "pall") == 0)
		{
			process_pall(stack, line_number);
		}
		else if (strcmp(cmd, "pint") == 0)
		{
			process_pint(stack, line_number);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			process_pop(stack, line_number);
		}
		else if (strcmp(cmd, "swap") == 0)
		{
			process_swap(stack, line_number);
		}
		else if (strcmp(cmd, "add") == 0)
		{
			process_add(stack, line_number);
		}
	}
}
