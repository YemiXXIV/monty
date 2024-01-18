#include "monty.h"

/**
 * process_file - Process the instructions in the given file
 * @file: Pointer to the file to be processed
 * @stack: Double pointer to the stack
 */
void process_file(FILE *file, stack_t **stack)
{
	char line[100];
	char *cmd, *value;
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		cmd = strtok(line, " \t\n");
		if (cmd != NULL)
		{
			if (strcmp(cmd, "push") == 0)
			{
				value = strtok(NULL, " \t\n");
				if (value == NULL || !is_number(value))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					fclose(file);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
				push(stack, atoi(value));
			}
			else if (strcmp(cmd, "pall") == 0)
			{
				pall(stack, line_number);
			}
			else if (strcmp(cmd, "pint") == 0)
			{
				pint(stack, line_number);
			}
		}

		line_number++;
	}
}
