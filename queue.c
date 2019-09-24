#include "monty.h"

void add_node(instruction_ins_t **rear, instruction_ins_t **front, instruction_t *node)
{
	instructions_int_t *new = malloc(sizeof(instructions_int_t));
	if (new == NULL)
	{
		/* malloc failed */
		exit(98);
	}
	new->

	if (rear == NULL)
	{
		*front = node;
		*rear = node;
		return;
	}
	(*rear)->prev = node;
}
