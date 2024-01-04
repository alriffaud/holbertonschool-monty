#include "monty.h"

char *line_token(FILE *fp, int j)
{
	char line[256][256];
	unsigned int i;

	for (i = 0; fgets(line[i], sizeof(line[i]), fp) != NULL; i++)
                line[i][strcspn(line[i], "\n")] = '\0';
       	/*printf("%s\n", line[2]);*/
	return (line[j]);
}
