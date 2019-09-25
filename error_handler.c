#include "monty.h"

void usage_err()
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

void open_err(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

void invalid_err(char *opcode, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

void malloc_err()
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void pint_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}
void pop_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}
void swap_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}
void add_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}
void sub_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
void div_err1(unsigned int line)
{
 	fprintf(stderr, "L%u: can´t div, stack too short\n", line);
	exit(EXIT_FAILURE);
}
void div_err2(unsigned int line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}
void mul_err(unsigned int line)
{
	fprintf(stderr, "L%u: can´t mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}
void mod_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line);
	exit(EXIT_FAILURE);
}
