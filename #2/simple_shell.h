#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

int execute(char **args);
int execute_command(char *command, char *environment);
void prompt(void);
char *read_input(void);
char **tokenize(char *line);
void free_array(char **array);
void handle_non_interactive_mode(char **environment);

#endif
