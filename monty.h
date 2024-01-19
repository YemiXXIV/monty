#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of
 * a stack (or queue)
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

void push(stack_t **stack, int value);
void process_pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
int is_number(char *str);
void process_file(FILE *file, stack_t **stack);
void process_pint(stack_t **stack, unsigned int line_number);
void process_pop(stack_t **stack, unsigned int line_number);
void process_swap(stack_t **stack, unsigned int line_number);
void process_add(stack_t **stack, unsigned int line_number);
void process_opcode(char *line, stack_t **stack, unsigned int line_number);
void process_push(stack_t **stack, unsigned int line_number);
#endif
