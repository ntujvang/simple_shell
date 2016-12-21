#include "shell.h"

char **tokenize(char *str)
{
        int buffer, i;
        char **token;
        char *hold;

        i = 0;
        buffer = 1024;
        token = malloc(buffer * sizeof(char *));
        if (token == NULL)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }
        hold = strtok(str, " \n");
        while (hold != NULL)
        {
                token[i] = hold;
                i++;
                hold = strtok(NULL, " \n");
        }
        token[i] = NULL;
        return (token);
}
