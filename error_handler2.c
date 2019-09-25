#include "monty.h"

/**
 * push_err - Handle error if there is not an integer or not argument given
 * @line: The function´s parameter
 * Return: Void
 */

void push_err(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}


/**
 * pop_err - Handle error for deletion of an empty stack
 * @line: The function´s parameter
 * Return: void
 */

void pop_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}

/**
 * swap_err - Error when can´t swap.
 * @line: The function´s parameter
 * Return: void
 */

void swap_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * add_err - Error when can´t add.
 * @line: The function´s parameter
 * Return: void
 */

void add_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * sub_err - Error when can´t do subtraction
 * @line: The function´s parameter
 * Return: void
 */

void sub_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
