#include "simple_shell.h"

/**
 * tokenize - splits a string into an array of tokens
 * @str: string to tokenize
 * Return: an array of strings with tokens
*/

char **tokenize(char *line) 

{
    char **tokens = NULL;
    char *token = strtok(line, " ");
    int token_count = 0;

    while (token) 
    {
        tokens = (char **)malloc(sizeof(char *) * (token_count + 1));
        if (tokens == NULL) 
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    tokens = (char **)malloc(sizeof(char *) * (token_count + 1));
    if (tokens == NULL) 
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    tokens[token_count] = NULL;

    return (tokens);
}
