#include "simple_shell.h"

/**
 * main - gets user input and calls
 * function(s) to perform commmand
 * @ac: argument count
 * @av: argument vector (array)
 * Return: 0. 
 */

int main(int ac, char **av)

{
	char *line;
	char **args;
	int status;
	bool running = true;

	(void)ac;
	(void)av;

	while (running)
	{
		prompt();
		line = read_input();

		if (line == NULL)
			break;

		args = tokenize(line);
		status = execute(args);
		free(line);
		free_array(args);

		if (status == -1)
		{
			running = false;
		}
	}
	return (0);

}
