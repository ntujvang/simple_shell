#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple.h"
extern char **environ;

char *_getenv(const char *name)
{
	char *env;
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		env = strtok(environ[i], "=");
		if (strcmp(env, name) == 0)
		{
			env = strtok(NULL, "=");
			return(env);
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *env, *hold;
	unsigned int i;
	cmd_finder *head, *list;

	env = _getenv("PATH");
	i = 0;
	/* everything below this line creates a linked list of PATH
	   use the _getenv you made Sam */
	head = NULL;
	hold = strtok(env, ":");
	while (hold != '\0')
	{
		list = malloc(sizeof(cmd_finder));
		if (list == NULL)
			return (-1);
		list->str = hold;
		list->next = head;
		head = list;
		printf("%s\n", list->str);
		hold = strtok(NULL, ":");
		i++;
	}
	return (0);
}
