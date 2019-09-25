#include "monty.h"

/**
 * usage_err - How the progam works
 * void: Return
 * Return: void
 */

void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_err - The errors about open files
 * @file: The file to open
 * Return: void
 */

void open_err(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * invalid_err - Unknown instructions
 * @opcode: The function´s parameter
 * @line: The line executed
 * Return: void
 */

void invalid_err(char *opcode, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err - Handle error when malloc failed
 * void: Return nothing
 * Return: void
 */

void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * pint_err - Handle error when stack is empty
 * @line: The line executed
 * Return: void
 */

void pint_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}
