#include "monty.h"

/**
 * pint - This function prints the value at the top of the stack.
 * @h: It's a pointer to the stack.
 * @a: It's the number of line.
 *
 * Return: None.
 */
void pint(stack_t **h, unsigned int a)
{
	stack_t *current = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	(void) a;
	printf("%d\n", current->n);
}
