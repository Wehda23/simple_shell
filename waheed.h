#ifndef WAHEED_H
#define WAHEED_H

/* imports standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/* constants */

#define BUFFER 1024
extern char **environ;

/* prompt.c */
void prompt(void);

/* _getline.c */
char *getUserInput();
char *handleEnter(char *input);
void handleHashtag(char *input);
char *removeLeadingSpaces(char *input);
char *remove_semicolon(char *str);

/* checkers.c */
int exit_check(char *string);
int buildin_checks(char *string);

/* execute_commands.c */
int execute_command(char **cmd, char *file);
int execute_echo(char **cmd);

/* semi_colon_parser.c */
char *remove_surrounding_spaces(char *str);
char **semicolon_parser(char *input);
void free_semicolon_memory(char ***commands);

/* _strtok.c */
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);

/* cmd_parser.c */
char **cmd_parser(char *input, char *delim);
void free_cmd_result(char ***result);
char *replace_space_within_quotes(char *input, char replacement);
void revert_replacement_to_spaces(char ***commands, char replacement);

/* exit_command.c */
void exit_command(void);

/* printers.c */
void cprint(char *string);
void errprint(char *string);
void print_commands(char **commands);

/* command_path.c */
char *_getenv(char *name);
char *build_path(char *token, char *value);
int cmd_finder(char **cmd);

/* string_handers1.c */
int _strlen(char *string);
int _strcmp(char *first, char *second);
int _atoi(char *string);
char *my_strdup(const char *str);
int _strncmp(const char *first, const char *second, size_t n);

#endif