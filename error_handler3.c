#include "monty.h"

/**
 * div_err1 - Error when can´t divide, stack is short
 * @line: The function´s parameter
 * Return: void
 */

void div_err1(unsigned int line)
{
	fprintf(stderr, "L%u: can´t div, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * div_err2 - Error when can´t divide by zero
 * @line: The function´s parameter
 * Return: void
 */

void div_err2(unsigned int line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mul_err - Error when can´t multiply
 * @line: The function´s parameter
 * Return: void
 */

void mul_err(unsigned int line)
{
	fprintf(stderr, "L%u: can´t mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mod_err - Error when can´t mod
 * @line: The function´s parameter
 * Return: void
 */
void mod_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line);
	exit(EXIT_FAILURE);
}
