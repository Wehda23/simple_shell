#ifndef WAHEED_H
#define WAHEED_H

/* imports standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* constants */

#define BUFFER 1024

/* prompt.c */
void prompt(void);

/* _getline.c */
char *getUserInput();
char *handleEnter(char *input);
void handleHashtag(char *input);
char *removeLeadingSpaces(char *input);
char *remove_semicolon(char *str);

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

/* printers.c */
void cprint(char *string);
void errprint(char *string);

/* string_handers1.c */
int _strlen(char *string);
int _strcmp(char *first, char *second);
int _atoi(char *string);
char *my_strdup(const char *str);

#endif