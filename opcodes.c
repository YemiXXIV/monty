#include "monty.h"

/**
 * process_pall - Prints all the values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */

void process_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * process_pint - Print the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */

void process_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * process_pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */

void process_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * process_push - Processes the "push" opcode
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty bytecode file
 */

void process_push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \t\n");

	if (value_str == NULL || !is_number(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	push(stack, atoi(value_str));
}


/**
 * free_stack - Frees a stack
 * @stack: Double pointer to the stack
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
