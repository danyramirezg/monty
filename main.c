#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: 2 (usage monty file)
 * @argv: monty file with opcodes
 * Return: void
 */
int main(int argc, char *argv[])
{
	/*stack_t * top = NULL;*/
	stack_ins_t *front = NULL;
	stack_ins_t *rear = NULL;
	stack_ins_t *current = NULL;

	FILE *fp;
	char *buff = NULL;
	size_t bytes = 1024;

	(void)argv;
	if (argc != 2)
		write(2, USAGE, sizeof(USAGE));


	fp = fopen("opcodes.m", "r");
	if (!fp)
	{
		/* print error, couldn't read file */
	}

	while (getline(&buff, &bytes, fp) != EOF)
	{
		instruction_t *ins = malloc(sizeof(instruction_t));
		if (!ins)
		{
			/* print error, couldn't malloc */
		}
		ins->opcode = buff;
		push(&rear, &front, ins);
	}
	current = rear;
	while (current != NULL)
	{
		printf("%s\n", current->ins->opcode);
		current = current->next;
	}

	return (EXIT_SUCCESS);
}

