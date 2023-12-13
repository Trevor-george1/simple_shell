#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARG_COUNT 10

extern char **environ;

void executeCommand(char *command, char **args, char *program_name);
char *get_line1();
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void parse_arguments(char *line,
char *command, char **args, size_t *arg_count);
void print_environment(void);
char *my_strtok(char *str, const char *delimiters);
#endif
