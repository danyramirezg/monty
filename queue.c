#include "monty.h"

/**
* queue_push - Insertion of an element
* @front: front of queue
* Return: void
*/
void queue_push(stack_t **front)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *last;

	if (new == NULL)
		malloc_err();
	new->n = 0;
	new->prev = NULL;
	new->next = NULL;

	if (*front == NULL)
	{
		*front = new;
		return;
	}
	last = *front;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = NULL;
}
/**
 * queue_pop - Deletion of an element
 * @front: front of queue
 * @line: line number
 * Return: void
*/
void queue_pop(stack_t **front, unsigned int line)
{
	stack_t *new_front;

	if (*front == NULL)
		pop_err(line);

	new_front = (*front)->next;
	free(*front);
	*front = new_front;
}
