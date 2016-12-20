#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
extern char **environ;

char *_getenv(const char *name)
{
	char *s;
	int i;

	i = 0;
	s = environ[0];
	while (s != NULL)
	{
		if (_strcmp(name, s) == 0)
		{
			return(s);
		}
		i++;
		s = environ[i];
	}
	return (NULL);
}

int link_lister(cmd_finder **head)
{
	char *env, *hold;
	unsigned int i;
	cmd_finder *list;

	env = _getenv("PATH");
	i = 0;
	/* everything below this line creates a linked list of PATH
	   use the _getenv you made Sam */
	*head = NULL;
	hold = strtok(env, ":");
	while (hold != '\0')
	{
		list = malloc(sizeof(cmd_finder));
		if (list == NULL)
			return (-1);
		list->str = hold;
		list->next = *head;
		*head = list;
		hold = strtok(NULL, ":");
		i++;
	}
	return (0);
}

int _strcmp(const char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '=')
		return (0);
}
