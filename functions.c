#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple.h" 

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

char *read_input(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return (line);
}

char **tokenize(char *line)
{
    char **tokens = NULL;
    char *token = strtok(line, " \t\n");
    int token_count = 0;

    while (token)
    {
        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
        tokens[token_count++] = strdup(token);
        token = strtok(NULL, " \t\n");
        tokens[token_count] = NULL;
    }

    return tokens;
}

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
        return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
    } 
    else 
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    return 0;
}
