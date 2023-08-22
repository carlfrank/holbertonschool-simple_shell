#include "simple_shell.h"

void handle_non_interactive_mode(char *environment)

{
    input_line = NULL;
    size_t line_length = 0;
    ssize_t read_count;

    while ((read_count = getline(&input_line, &line_length, stdin)) != -1)
    {
        if (read_count > 0 && input_line[read_count - 1] == '\n')
            input_line[read_count - 1] = '\0'

        if (strcmp(input_line, "exit") == 0)
            break;

        if (input_line[0] == '\0' || input_line[0] == ' ')
            continue;

        execute_command(input_line, environment);
    }

    free(input_line);
}
