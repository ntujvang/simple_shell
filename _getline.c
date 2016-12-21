#include "shell.h"

char *_getline(void)
{
        char *str;
        ssize_t buffer, hold;

        buffer = 0;
        hold = getline(&str, &buffer, stdin);
	if (hold == EOF)
        {
                _puts("EOF\n");
                exit(0);
        }
        return (str);
}
