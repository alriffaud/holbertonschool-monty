#include "monty.h"


/**
 * process_line - This function processes each line in a file.
 * @opcodes: It's the array of opcodes.
 * @s: It's a pointer to the stack.
 * @line: It's a pointer to the line.
 * @fp: It's a pointer to the file.
 *
 * Return: None.
 */
void process_line(instruction_t opcodes[], stack_t **s, char *line, FILE *fp)
{
	char *token = strtok(line, " ");
	int i;

	while (token != NULL && strcmp(token, "$") != 0)
	{
		token[strcspn(token, "$")] = '\0';
		i = 0;
		while (opcodes[i].opcode != NULL && strcmp(token, opcodes[i].opcode) != 0)
			i++;
		if (opcodes[i].opcode != NULL)
		{
			token = strtok(NULL, " ");
			if (token != NULL)
				token[strcspn(token, "$")] = '\0';
			if (strcmp(opcodes[i].opcode, "push") == 0 && atoi(token) == 0
				&& strcmp(token, "0") != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				fclose(fp), free_stack(*s);
				exit(EXIT_FAILURE);
			}
			else if (token != NULL)
				opcodes[i].f(s, atoi(token));
			else
				if (strcmp(opcodes[i].opcode, "push") != 0)
					opcodes[i].f(s, line_count); }
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, token);
			fclose(fp), free_stack(*s), exit(EXIT_FAILURE); }
		token = strtok(NULL, " "); }
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
	instruction_t opcodes[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"nop", nop}, {"swap", swap}, {"add", add}, {NULL, NULL}};
	FILE *fp;
	char line[256];
	stack_t *s = NULL;
	/*unsigned int line_count;*/

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	for (line_count = 1; fgets(line, sizeof(line), fp) != NULL; line_count++)
	{
		line[strcspn(line, "\n")] = '\0';
		process_line(opcodes, &s, line, fp);
	}
	fclose(fp);
	free_stack(s);
	return (0);
}
