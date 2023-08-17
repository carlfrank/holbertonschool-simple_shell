#include "simple_shell.h"

/**
 * execute - execute a command
 * @args: array of arguments
 * Return: 0 on success, -1 on failure
*/

int execute(char **args)

{
    pid_t pid = fork();

    if (pid == 0) 
    {
        if (execve(args[0], args, NULL) == -1) 
        {
            perror("Exec failed");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) 
    {
        int status;
        waitpid(pid, &status, 0);
        return status;
    } 
    else 
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    return (0);
}

