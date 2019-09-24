#include "monty.h"

void push(stack_ins_t **rear, stack_ins_t **front, instruction_t *node)
{
	stack_ins_t *new = malloc(sizeof(stack_ins_t));
	if (new == NULL)
	{
		/* malloc failed */
		exit(98);
	}
	new->ins = node;
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
void pop(stack_ins_t **rear, stack_ins_t **front)
{
	stack_ins_t *delete = *front;
	
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

