#include "monty.h"
/**
 * pchar_err1 - error whent the ascii is out of range
 * @line: The function´s parameter
 * Return: void
 */
void pchar_err1(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
	exit(EXIT_FAILURE);
}
/**
 * pchar_err2 - empty stack error, can't pchar
 * @line: The function´s parameter
 * Return: void
 */
void pchar_err2(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
	exit(EXIT_FAILURE);
}
