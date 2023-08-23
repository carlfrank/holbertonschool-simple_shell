#include "simple_shell.h"

/*
get_paths - Extracts paths from the PATH environment variable
Return: A pointer to an array of strings containing the paths
NULL on failure or if PATH is not found
*/
char **get_paths(void)

{
    char path_env = getenv("PATH");
    int num_paths = 0;

    if (path_env == NULL)
    {
        perror("error ");
        return NULL;
    }

    for (int i = 0; path_env[i]; i++)
    {
        if (path_env[i] == ':')
            num_paths++;
    }

    char **paths = malloc(sizeof(char) * (num_paths + 2));
    if (paths == NULL)
    {
        perror("error ");
        return NULL;
    }

    char *token = strtok(path_env, ":");
    int index = 0;
    while (token != NULL)
    {
        paths[index] = token;
        index++;
        token = strtok(NULL, ":");
    }

    paths[index] = NULL;

    return paths;
}
