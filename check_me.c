#include "shell.h"

int check_me(char *buffer, cmd_finder *h, char **args)
{
        char *temp;
	int i;

        if (buffer[0] == '/')
        {
                if (access(buffer, X_OK) == 0)
                {
                        i = execute(buffer, args);
                        return (1);
                }
                return (0);
        }

        i = 0;
        temp = malloc(100);
        while (h != NULL)
        {
                /* gotta change these str functions */
                _strcpy(temp, h->str);
                strcat(temp, "/");
                strcat(temp, buffer);
                if (access(temp, X_OK) == 0)
                {
                        i = execute(temp, args);
                        break;
                }
                h = h->next;
	}
	free(temp);
        if (h == NULL)
                return (0);
        return (1);
}
