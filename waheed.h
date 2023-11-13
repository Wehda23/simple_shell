#ifndef WAHEED_H
#define WAHEED_H

/* Imports */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

/* Predefined constants */
#define COMMAND_BUFFER_SIZE 1024
#define NO_OF_COMMANDS_ALLOWED 100

/* prompt.c */
void prompt();

/* _getline.c */
int _getline(int fd, void *buf, int count);

/* string_handlers.c */
int _strlen(char *string);
int _atoi(char *string);

#endif