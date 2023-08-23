#include "simple_shell.h"

/**
 * read_input read a line a from stdin
 * Return:pointer to the new line
 */

char *read_input(void)

{
    char *line = NULL;
    size_t bufsize = 0;

    ssize_t chars_read = getline(&line, &bufsize, stdin);
    
    if (chars_read == -1) 
    {
        free(line);
        return NULL;
    }
    
    line[chars_read - 1] = '\0';
    return (line);
}
