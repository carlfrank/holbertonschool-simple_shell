#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple.h"

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

       if (status == -1)
       {
           running = false;
       }
   }
   free(line);
   return 0;
}
