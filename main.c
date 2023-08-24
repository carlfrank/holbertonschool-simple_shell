#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "simple.h"
/**
 * main - main functin
 * @argc: number of arguments
 * @argv: line of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (isatty(0))
	{
		interactive_loop();
	}
	else
	{
		noninteractive();
	}

	return (0);
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


/**
 * noninteractive - non interactive mode
 */
void noninteractive(void)
{
	char *line = NULL;

	line = read_input();

	if (line == NULL)
	{}

	if (strcmp(line, "exit\n") == 0)
	{}

	else
	{
		execute_command(line);
	}
	free(line);
}
