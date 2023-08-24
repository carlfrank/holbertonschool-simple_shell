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

    while ((line = read_input()) != NULL)
    {
        char *trimmed_line = whitespace_trimer(line);

        if (strcmp(trimmed_line, "exit") == 0)
        {
            free(trimmed_line);
            free(line);
            break;
        }
        else if (trimmed_line[0] != '\0')
        {
            execute_command(trimmed_line);
        }

        free(trimmed_line);
        free(line);
    }
}


/**
 * whitespace_trimer - remove leading and trailing whitespace from a string
 * @str: input string
 * Return: pointer to the trimmed string (caller must free it)
 */

char *whitespace_trimer(const char *str)
{
    size_t len;
    size_t start, end, trimmed_len;
    char *trimmed_str;

    if (str == NULL)
    {
        return NULL;
    }

    len = strlen(str);
    start = 0;
    end = len - 1;

    while (isspace(str[start]) && start < len)
    {
        start++;
    }

    while (isspace(str[end]) && end > start)
    {
        end--;
    }

    trimmed_len = end - start + 1;
    trimmed_str = (char *)malloc(trimmed_len + 1);

    if (trimmed_str == NULL)
    {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    strncpy(trimmed_str, str + start, trimmed_len);
    trimmed_str[trimmed_len] = '\0';

    return trimmed_str;
}