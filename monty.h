#ifndef _MONTY_H_
#define _MONTY_H_

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


/* Global variables*/
unsigned int line_count;

/* Structures */

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
	unsigned int n;
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

/* Functions */
void free_stack(stack_t *head);
void push(stack_t **head, unsigned int n);
void pall(stack_t **h, unsigned int a);
void pint(stack_t **h, unsigned int a);
void pop(stack_t **h, unsigned int a);
void nop(stack_t **h, unsigned int a);
void swap(stack_t **h, unsigned int a);
void add(stack_t **h, unsigned int a);

#endif
