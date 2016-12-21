#include "shell.h"

int builtinchecker(char *str, char **args)
{
        if (_strcmp(str, "exit") == 0)
                exitFunction(0, str, args);
        return (0);
}

void exitFunction(char *str, char **args)
{
        free(args);
        free(str);
        exit(98);
}

