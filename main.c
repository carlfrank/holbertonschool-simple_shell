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

    if (trimmed_len > 0 && trimmed_str[trimmed_len - 1] == '\n')
    {
        trimmed_str[trimmed_len - 1] = '\0';
    }

    return trimmed_str;
}