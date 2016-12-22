#include "shell.h"
/**
 * check_me - function to find commands
 * @buffer: the string going in
 * @h: link list
 * @args: arg looking for
 * Return: 1 for infinite loop
 */
int check_me(char *buffer, cmd_finder *h, char **args)
{
	char *temp;
	int i;

	if (buffer[0] == '\n')
		return (1);
	if (buffer[0] == '/')
	{
		if (access(buffer, X_OK) == 0)
		{
			i = execute(buffer, args);
			return (i);
		}
		return (0);
	}
	i = 0;
	temp = malloc(100);
	while (h != NULL)
	{
		_strcpy(temp, h->str);
		_strcat(temp, "/");
		_strcat(temp, buffer);
		if (access(temp, X_OK) == 0)
		{
			i = execute(temp, args);
			break;
		}
		h = h->next;
	}
	free(temp);
	return (1);
}
