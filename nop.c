#include"monty.h"

/**
 * nop - Doesnt do anything.
 * @h: It's a pointer to the stack.
 * @a: It's the number of line.
 *
 * Return: None.
 */

void nop(stack_t **h, unsigned int a)
{
	if (*h == NULL)
		return;
	(void) a;
}
