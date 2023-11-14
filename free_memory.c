#include "waheed.h"



/**
 * free_commands - function that frees memory allocated for commands
 * @commands: array of strings
 */

void free_commands(char ***commands)
{
	int index = 0;
	while ((*commands)[index] != NULL)
	{
		free((*commands)[index]);
		index++;
	}

	free(*commands);
}
