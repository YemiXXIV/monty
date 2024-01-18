#include "monty.h"

/**
 * main - The program begins
 * @argc: The number of arguments passed
 * @argv: The array containing arguments passed from the user
 * Return: 0 if successful
 */

int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack = NULL;

	if (!(argc > 1 && argc < 3))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_file(file, &stack);

	fclose(file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
