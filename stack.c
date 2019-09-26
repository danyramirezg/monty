#include "monty.h"
/**
 * stack_push - Insertion of an element
 * @top: top of stack
 * Return: void
*/
void stack_push(stack_t **top)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		malloc_err();
	}
	node->n = 0;
	node->prev = NULL;

	if (*top == NULL)
	{
		node->next = NULL;
		*top = node;
		return;
	}
	node->next = (*top);
	(*top)->prev = node;
	*top = node;
}
/**
 * stack_pop - Deletio of an element
 * @top: top of stack
 * @line: line number
 * Return: void
*/
void stack_pop(stack_t **top, unsigned int line)
{
	stack_t *node = *top;

	if (*top == NULL)
		pop_err(line);
	*top = (*top)->next;
	free(node);
}
