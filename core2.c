#include "monty.h"
/**
 * nop - does nothing
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void nop(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
}
/**
 * pchar - prints the char at the top of the stack
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pchar(stack_t **top, unsigned int line)
{
	int ascii;

	if (*top == NULL)
		pchar_err2(line);

	ascii = (*top)->n;

	if (ascii < 0 || ascii > 127)
		pchar_err1(line);

	putchar(ascii);
	putchar('\n');
}
/**
 * pstr - prints the string starting at the top of the stack
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pstr(stack_t **top, unsigned int line)
{
	stack_t *current;

	(void)line;
	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	current = *top;
	while (current)
	{
		int ascii = current->n;

		if (ascii <= 0 || ascii > 127)
			break;
		putchar(ascii);
		current = current->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void rotl(stack_t **top, unsigned int line)
{
	stack_t *new_top, *first, *last;

	(void)line;
	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;

	first = *top;
	last = *top;
	while (last->next)
		last = last->next;
	new_top = (*top)->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	new_top->prev = NULL;
	*top = new_top;
}
/**
 * rotr - rotates the stack to the bottom
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void rotr(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
}
