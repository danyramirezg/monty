#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: 2 (usage monty file)
 * @argv: monty file with opcodes
 * Return: void
 */
int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	FILE *fp;
	char *buff = NULL, *token1 = NULL, *token2 = NULL;
	size_t bytes = 1024;
	unsigned int line_count = 1;

	if (argc != 2)
		usage_err();
	fp = fopen("opcodes.m", "r");
	if (!fp)
		open_err(argv[1]);

	while (getline(&buff, &bytes, fp) != EOF)
	{
		int len = strlen(buff);

		if (len == 1)
			continue;
		buff[strlen(buff) - 1] = '\0';
		token1 = strtok(buff, " ");
		token2 = strtok(NULL, " ");
		execute_opcode(token1, &top, line_count);
		/* hardcode push value */
		if (strcmp(token1, "push") == 0 && token2 != NULL)
		{
			top->n = atoi(token2);
		}
		line_count++;
	}
	fclose(fp);
	free(buff);
	return (EXIT_SUCCESS);
}
/**
 * execute_opcode - execute the opcode found in the line
 * @token: opcode
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void execute_opcode(char *token, stack_t **top, unsigned int line)
{
	int i, len;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div1},
		{"mul", mul},
		{"mod", mod}
	};
	len = (int)(sizeof(opcodes) / sizeof(instruction_t));
	for (i = 0; i < len; i++)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(top, line);
			return;
		}
	}
	invalid_err(token, line);
}
/**
 * push - pushes a new node to stack
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void push(stack_t **top, unsigned int line)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		malloc_err();
	}
	node->n = 0;
	node->prev = NULL;

	if (*top == NULL)
	{
		node->next = NULL;
		*top = node;
		return;
	}
	node->next = (*top);
	(*top)->prev = node;
	*top = node;
	(void)line;
}
/**
 * pall - prints all elements of stack
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pall(stack_t **top, unsigned int line)
{
	stack_t *current = *top;

	if (*top == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line;
}
/**
 * pint - prints element at top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pint(stack_t **top, unsigned int line)
{
	if (*top == NULL)
		pint_err(line);
	printf("%d\n", (*top)->n);
}

/**
 * pop - removes element at top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void pop(stack_t **top, unsigned int line)
{
	stack_t *node = *top;

	if (*top == NULL)
		pop_err(line);
	*top = (*top)->next;
	free(node);
}
/**
 * swap - swaps the elemnt at top with the second top
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void swap(stack_t **top, unsigned int line)
{
	stack_t *a, *b, *c;

	if (*top == NULL || (*top)->next == NULL)
		swap_err(line);

	a = *top;
	b = (*top)->next;
	c = b->next;
	*top = b;
	b->next = a;
	a->prev = b;
	a->next = c;
	if (c)
		c->prev = a;
}
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
