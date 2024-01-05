#include "monty.h"

/**
 * push - This function push an element into a stack.
 * @head: It's a pointer to the stack.
 * @n: It's the value of the element to add.
 *
 * Return: None.
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return;
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		new_node->next->prev = new_node;
	*head = new_node;
}
