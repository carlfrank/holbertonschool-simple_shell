#include "simple_shell.h"

/**
 * free_array - free malloc
 * @arr: arguments to free
 * Return: void
 */

void free_array(char **array)

/* Mientras el array tenga info vas a liberar argumento por argumento */

{
    int i = 0;

    while (array [i])
    {
        free(array[i]);
        i++;
    }

    free(array);
}
