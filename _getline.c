#include "waheed.h"


/**
 * _getline - function that takes user input.
 * 
 * @fd: File descriptor.
 * @buf: buffer at which it stores the input.
 * @count: read up count in integers.
 * @return int
 */
int _getline(int fd, void *buf, int count) {
	char c, *buffer = (char *)buf;
	int  index, read_character, hashtage_position = -1;

	/* Basically telling it if it counters EOF of ENTER it breaks the loop*/
	for (index = 0; c != EOF && c != '\n' && index < count; index++)
	{
		fflush(stdin);
		read_character = read(fd, &c, 1);
		if (read_character == 0)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		} else if (read_character == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
		else
		{   /* Remove any preceeding whitespaces */
			if (index == 0 && c == ' ')
				index--;
			else
				buffer[index] = c;
		}

		/* Handle Hastage */
		if (c == '#')
		{
			hashtage_position = index;
		}
	}
	index--;
	if (hashtage_position == -1)
	{
		buffer[index] = '\0';
		index == 0 ? index : index--;
	}
	else
	{
		buffer[hashtage_position] = '\0';
		index = hashtage_position;
	}

	return (index);
}
