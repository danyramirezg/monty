#include "monty.h"

void push(instruction_ins_t **rear, instruction_ins_t **front, instruction_t *node)
{
	instruction_int_t *new = malloc(sizeof(instruction_int_t));
	if (new == NULL)
	{
		/* malloc failed */
		exit(98);
	}
	new->inst = node;
	new->prev = NULL;
	new->next = NULL;


	if (rear == NULL)
	{
		*front = node;
		*rear = node;
		return;
	}
	(*rear)->prev = new;
	next->nex = *rear;
	*rear = new;
}
void pop(instruction_ins_t **rear, **front)
{
	instruction_int_t *delete = *front;
	
	if (delete->prev == NULL)
	{
		free(delete);
		*front = NULL;
		*rear = NULL;
		return;		
	}
	delete->prev->next = NULL
	*front = prev;
	free(delete);
}

