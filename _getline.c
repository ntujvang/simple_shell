#include "shell.h"
/**
 * _getline - function for get line
 * Return: copy of stdin as string
 */
char *_getline(void)
{
	char *str;
	size_t buffer;
	int hold;

	buffer = 0;
	hold = getline(&str, &buffer, stdin);
	if (hold == EOF)
	{
		_puts("EOF\n");
		exit(0);
	}
	return (str);
}
