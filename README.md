# C-Simple Shell

Group project for Simple Shell

## Description

The shell is a command line interface(CLI) programm that takes commands
from the keyboard and gives them to the operating system to perform.
Commands can be interactive and non-interactive.

## Syntax

/bin/command

## Compiler

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Specifiers

- $

## Example
```
in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```

## Authors

Miguel Figuroa, Carlos Carrasquillo and Nadja Miranda
