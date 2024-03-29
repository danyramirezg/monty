#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: 2 (usage monty file)
 * @argv: monty file with opcodes
 * Return: void
 */
int main(int argc, char *argv[])
{
	stack_t *top = NULL, *current = NULL;
	FILE *fp;
	char *buff = NULL, *token1 = NULL, *token2 = NULL;
	size_t bytes = 1024;
	unsigned int line_count = 1;

	is_stack = 1;
	if (argc != 2)
		usage_err();
	fp = fopen(argv[1], "r");
	if (!fp)
		open_err(argv[1]);
	while (getline(&buff, &bytes, fp) != EOF)
	{
		token1 = strtok(buff, " \n");
		token2 = strtok(NULL, " \n");
		if (!token1 || token1[0] == '#')
		{
			line_count++;
			continue;
		}
		execute_opcode(token1, &top, line_count);
		if (strcmp(token1, "push") == 0)
		{
			if (token2 == NULL || is_a_number(token2) == -1)
				push_err(line_count);
			if (is_stack == 1)
				top->n = atoi(token2);
			else
			{
				current = top;
				while (current->next)
					current = current->next;
				current->n = atoi(token2);
			}
		}
		line_count++;
	}
	free_all(&top, buff, fp);
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
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue}
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
 * is_a_number - test if a string is a number
 * @s: string
 * Return: -1 if not number, 1 otherwise
 */
int is_a_number(char *s)
{
	int i = 0;

	if (!s)
		return (-1);

	while (s[i])
	{
		if (s[i] != 45 && isdigit(s[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}
/**
 * free_all - frees and close files
 * @top: top of stack
 * @buff: string buffer
 * @fp: file descriptor
 * Return: void
 */
void free_all(stack_t **top, char *buff, FILE *fp)
{
	stack_t *tmp = NULL;

	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
	free(buff);
	fclose(fp);
}
