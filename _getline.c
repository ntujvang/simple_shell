#include "shell.h"

char *_getline(void)
{
        char *str;
        size_t buffer;
	size_t hold;
        buffer = 0;
        hold = getline(&str, &buffer, stdin);
	if (hold == EOF)
        {
                _puts("EOF\n");
                exit(0);
        }
        return (str);
}
