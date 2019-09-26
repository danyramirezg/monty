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
