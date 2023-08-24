#include "simple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

/**
 * read_input - read input from stdin
 *
 * Return: A dynamically allocated string containing the user input.
 *         The caller is responsible for freeing the memory.
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * free_args - free memory
 * @args: arguments
*/
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * tokenize - divide arguments
 * @line: of arguments
 * Return: tokens
*/
char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token = strtok(line, " \t\n");
	int token_count = 0;

	while (token)
	{
		tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
		if (tokens == NULL)
		{
			perror("realloc error");
			exit(EXIT_FAILURE);
		}
		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("strdup error");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, " \t\n");
	}
	tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	if (tokens == NULL)
	{
		perror("realloc error");
		exit(EXIT_FAILURE);
	}
	tokens[token_count] = NULL;

	return (tokens);

}

/**
 * execute - execute command line
 * @args: line of arguments
 *
 * Return: 0
 */

int execute(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
	else
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void noninteractive(void)
{
    char *line = NULL;
    int running = 1; 

    while (running && (line = read_input()) != NULL)
    {
        char *trimmed_line = whitespace_trimer(line);

        if (strcmp(trimmed_line, "exit") == 0)
        {
            free(trimmed_line);
            free(line);
            running = 0; 
        }
        else if (strlen(trimmed_line) > 0)
        {
            int status = execute_command(trimmed_line);

            if (status != 0)
            {
                free(trimmed_line);
                free(line);
                exit(EXIT_FAILURE);
            }
        }

        free(trimmed_line);
        free(line);
    }

    printf("No commands executed.\n");
    exit(EXIT_SUCCESS);
}
