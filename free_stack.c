#include "monty.h"

/**
 * free_stack - This function frees a dlistint_t list.
 * @head: It's a pointer to the first element of the list.
 *
 * Return: None.
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
