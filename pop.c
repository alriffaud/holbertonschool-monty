#include "monty.h"

/**
 * pop - removes the top element of the stack..
 * @h: It's a pointer to the stack.
 * @a: It's the value of the element to add.
 *
 * Return: None.
 */

void pop(stack_t **h, unsigned int a)
{
	stack_t *current = *h;

	void(a);

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}

	if (current->next != NULL)
	{
		current->next->prev = NULL;
	}

	*h = current->next;
	free(current);
}
