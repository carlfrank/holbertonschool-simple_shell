#include "simple_shell.h"

/**
execute_command - Execute a command using fork and execve
@command: The command to execute
@environment: The environment variables
*/


int execute(char **args)
{
    pid_t pid = fork();

    if (pid < 0) 
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) 
    {
        execvp(args[0], args);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } 
    else 
    {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}