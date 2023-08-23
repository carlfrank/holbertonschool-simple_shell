#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple.h"

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

   return 0;
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
   }
   free(line);
}

void noninteractive(void)
{
    char *line = NULL; 
    line = read_input();

    if (line == NULL)
    {}

    if (strcmp(line, "exit\n") == 0)
    {}
    else
    {
        execute_command(line);
    }
    free(line);
}
