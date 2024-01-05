#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @h: It's a pointer to the stack.
 * @a: It's the number of line.
 *
 * Return: None.
 */

void swap(stack_t **h, unsigned int a)
{
	stack_t *current = *h;
	stack_t *aux = current->next->next;

	(void) a;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	
	*h = current->next;
	if (current->next->next != NULL)
	{
		current->next->next->prev = current;
	}
	current->next->prev = NULL;
	current->next->next = current;
	current->next = aux;
	current->prev = *h;
}
