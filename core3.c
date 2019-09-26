#include "monty.h"
/**
 * stack - sets the format of the data to a stack
 * @front: stack
 * @line: line of the instruction
 * Return: void
 */
void stack(stack_t **front, unsigned int line)
{
	is_stack = 1;
	(void)front;
	(void)line;
}
/**
 * queue - sets the format of the data to a queue
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void queue(stack_t **top, unsigned int line)
{
	is_stack = 0;
	(void)top;
	(void)line;
}
