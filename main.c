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
