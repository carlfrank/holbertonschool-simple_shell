#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple.h"

int execute_command(char *command)
{
    int status = -1;
    char *line = strdup(command);
    char **args = tokenize(line);

    if (args[0] != NULL)
    {
        status = execute(args);
        free(args);
        free(line);

    }
    
    return status;
}

void free_array(char **args)
{
    free(args);
}
