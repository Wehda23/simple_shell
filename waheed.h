#ifndef WAHEED_H
#define WAHEED_H

/* Imports */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/* Predefined constants */
#define COMMAND_BUFFER_SIZE 1024
extern char **environ;

/* prompt.c */
void prompt(void);

/* listing_command.c */
void ls_command(char **command, char *file);
void echo_command(char **commands, char *file);
void exit_command(char **commands);

/* env_commands.c */
void print_env(char *file);
void add_env(char **commands, char *file);
void remove_env(char **commands, char *file);

/* _getline.c */
int _getline(int fd, void *buf, int count);

/* _strtok.c */
char *_strtok(char *command, char *delim);
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
