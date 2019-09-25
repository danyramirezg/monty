#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @top: Double pointer to the structure
 * @line: The line to be executed
 * Return: void
 */

void add(stack_t **top, unsigned int line)
{
	stack_t *new_top;

	if (*top == NULL || (*top)->next == NULL)
		add_err(line);

	new_top = (*top)->next;
	new_top->n += (*top)->n;
	pop(top, line);
}
/**
 * sub - Subtracts the top element of the stack from the second top
 * @top: Double pointer to the structure
 * @line: The line to be executed
 * Return: void
 */

void sub(stack_t **top, unsigned int line)
{
	stack_t *new_top;

	if (*top == NULL || (*top)->next == NULL)
		sub_err(line);

	new_top = (*top)->next;
	new_top->n -= (*top)->n;
	pop(top, line);
}

/*
* div1 - Divides the seccond top element of the stack by the top element
* @top: Double pointer to the structure
* @line: The line to be executed
* Return: void
*/

void div1(stack_t **top, unsigned int line)
{
	stack_t *new_top;

	if (*top == NULL || (*top)->next == NULL)
	div_err1(line);

	if ((*top)->n == 0)
		div_err2(line);

	new_top = (*top)->next;
	new_top->n = (new_top->n) / (*top)->n;
	pop(top, line);
}

void mul(stack_t **top, unsigned int line)
{
	stack_t *new_top;

	if (*top == NULL || (*top)->next == NULL)
		mul_err(line);

	new_top = (*top)->next;
	new_top->n *= (*top)->n;
	pop(top, line);
}
void mod(stack_t **top, unsigned int line)
{
	stack_t *new_top;

	if (*top == NULL || (*top)->next ==  NULL)
		mod_err(line);
	if ((*top)->n == 0)
		div_err2(line);

	new_top = (*top)->next;
	new_top->n = (new_top->n) % (*top)->n;
	pop(top, line);
}
