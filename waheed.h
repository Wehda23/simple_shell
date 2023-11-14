#ifndef WAHEED_H
#define WAHEED_H

/* Imports */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

/* Predefined constants */
#define COMMAND_BUFFER_SIZE 1024
extern char **environ;

/* prompt.c */
void prompt();
/* listing_command.c */
void ls_command(char **command, char *file);

/* _getline.c */
int _getline(int fd, void *buf, int count);

/* _strtok.c */
char * _strtok(char *command, char *delim);
void get_commands(char *command, char ***commands);

/* string_handlers.c */
int _strlen(char *string);
int _atoi(char *string);
int _strcmp(char *first, char *second);

/* printers.c */
void print_commands(char **commands);

/* free_memory.c */
void free_commands(char ***commands);

#endif