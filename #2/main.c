#include "simple_shell.h"

/*
main - Entry point for the simple shell program
@argc: The argument count (unused)
@argv: The argument vector (unused)
@env: The environment variables
Return: Always 0 */

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    int status;
    bool running = true;

    (void)argc;
    (void)argv;

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
            status = execute_command(line, *env);
        }


        free(line);

        if (status == -1) 
        {
            running = false;
        }
    }

    return 0;
}
