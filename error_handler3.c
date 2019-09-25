#include "monty.h"

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
