#include "monty.h"

/**
 * swap - swaps the elemnt at top with the second top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void swap(stack_t **top, unsigned int line)
{
	stack_t *a, *b, *c;

	if (*top == NULL || (*top)->next == NULL)
		swap_err(line);

	a = *top;
	b = (*top)->next;
	c = b->next;
	*top = b;
	b->next = a;
	a->prev = b;
	a->next = c;
	if (c)
		c->prev = a;
}
/**
 * pop - removes element at top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pop(stack_t **top, unsigned int line)
{
	stack_t *node = *top;

	if (*top == NULL)
		pop_err(line);
	*top = (*top)->next;
	free(node);
}
/**
 * pint - prints element at top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pint(stack_t **top, unsigned int line)
{
	if (*top == NULL)
		pint_err(line);
	printf("%d\n", (*top)->n);
}
/**
 * pall - prints all elements of stack
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pall(stack_t **top, unsigned int line)
{
	stack_t *current = *top;

	if (*top == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line;
}
/**
 * push - pushes a new node to stack
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void push(stack_t **top, unsigned int line)
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
	(void)line;
}
