#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @h: It's a pointer to the stack.
 * @a: It's the number of line.
 *
 * Return: None.
 */

void add(stack_t **h, unsigned int a)
{
	stack_t *current = *h;
	unsigned int sum;

	(void) a;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	sum = curren->n + current->next->n;
	current->next->n = sum;

	pop(*h, line_count);

}
