#include "monty.h"

/**
* queue_push - Insertion of an element
* @rear: Entry point
* @front: Exit point
* @n: integer
* Return: void
*/
void queue_push(stack_t **rear, stack_t **front, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		/* malloc failed */
		exit(98);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;


	if (*rear == NULL)
	{
		*front = new;
		*rear = new;
		return;
	}
	(*rear)->prev = new;
	new->next = *rear;
	*rear = new;
	}
/**
* queue_pop - Deletion of an element
* @rear: Entry point
* @front: Exit point
* Return: void
*/

void queue_pop(stack_t **rear, stack_t **front)
{
	stack_t *delete = *front;

	if (delete->prev == NULL)
	{
		free(delete);
		*front = NULL;
		*rear = NULL;
	return;
	}
	delete->prev->next = NULL;
	*front = delete->prev;
	free(delete);
}
