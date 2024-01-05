#include "monty.h"

/**
 * pall - This function prints all the elements of the stack.
 * @h: It's a pointer to the stack.
 * @a: It's the number of line.
 *
 * Return: None.
 */
void pall(stack_t **h, unsigned int a)
{
	stack_t *current = *h;

	(void) a;
	if (*h == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
