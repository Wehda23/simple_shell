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
    char character, *buffer = (char *)buf;
    int  index, read_character;

    /* Basically telling it if it counters EOF of ENTER it breaks the loop*/
    for (index = 0; character  != EOF && character != '\n' && index < count; index++)
    {
        fflush(stdin);
        read_character = read(fd, &character, 1);
        if (read_character == 0)
        {
            exit(EXIT_SUCCESS);
        } else if (read_character == -1)
        {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
        else
            buffer[index] = character;
    }

    buffer[index] = '\0';

    return (index - 1);
}
