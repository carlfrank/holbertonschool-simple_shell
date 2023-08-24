#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple.h"
/**
 * execute_command - execute a command
 * @command: command to be executed
 *
 * Return: status
 */

int execute_command(char *command)
{
    char *line = strdup(command);
    char **args = tokenize(line);

    if (args[0] != NULL)
    {
        int status = execute(args);
        int i; 

     
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }

        free(args);
        free(line);
        return status;  
    }
    else
    {
        free(line);
        return -1; 
    }
}

/**
 * interactive_loop - printint the $
*/
void interactive_loop(void)
{
	char *line = NULL;
	int status;
	bool running = true;

	while (running)
	{
		printf("$ ");
		line = read_input();

		if (line == NULL)
		{
			break;
		}

		if (strcmp(line, "exit\n") == 0)
		{
			running = false;
		}
		else
		{
			status = execute_command(line);
		}

		if (status == -1)
		{
			running = false;
		}

		free(line);
	}
}