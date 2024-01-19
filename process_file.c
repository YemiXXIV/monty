#include "monty.h"

/**
 * process_file - Process the instructions in the given file
 * @file: Pointer to the file to be processed
 * @stack: Double pointer to the stack
 */
void process_file(FILE *file, stack_t **stack)
{
	char line[100];
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		process_opcode(line, stack, line_number);
		line_number++;
	}
}
