#include "monty.h"

/**
 * num_of_lines - This function returns the number of lines in a file.
 * @str: It's the pointer to the file.
 *
 * Return: An integer representing the number of lines or NULL if there is
 * any error.
 */
int num_of_lines(FILE *str)
{
	int count = 0;
	char c;

	if (str == NULL)
	{
		return (0);
	}

	while ((c = fgetc(str)) != EOF)
	{
		if (c == '\n')
		{
			count++;
		}
	}
	return (count);
}


/**
 * main - This program implements the opcodes functions from a monty file.
 * @argc: Is the number of arguments passed to the program.
 * @argv: Is a one-dimensional array of strings.
 *
 * Return: Always 0;
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};
	FILE *fp;
	unsigned int i, j;
	char line[256], *token;
	stack_t *s = NULL;

	if (argc != 2)
		printf("USAGE: monty file\n"), exit(EXIT_FAILURE);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		printf("Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	for (j = 1; fgets(line, sizeof(line), fp) != NULL; j++)
	{
		line[strcspn(line, "\n")] = '\0';
		token = strtok(line, " ");
		if (strcmp(token, "$") == 0)
			break;
		while (token != NULL)
		{
			token[strcspn(token, "$")] = '\0';
			i = 0;
			while (opcodes[i].opcode != NULL && strcmp(token, opcodes[i].opcode) != 0)
				i++;
			if (opcodes[i].opcode != NULL)
			{
				token = strtok(NULL, " ");
				/*if (strcmp(token, "$") == 0) break;*/
				if (token != NULL)
					token[strcspn(token, "$")] = '\0', opcodes[i].f(&s, atoi(token));
				else
					opcodes[i].f(&s, j); }
			else
			{
				printf("L%d: unknown instruction %s\n", j, token);
				free_stack(s), exit(EXIT_FAILURE); }
			token = strtok(NULL, " "); } }
	fclose(fp), free_stack(s);
	return (0);
}
