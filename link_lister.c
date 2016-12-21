#include "shell.h"
/**
 * _getenv - gets a value
 * @name: the variable we want
 * Return: NULL
 */
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
			return (s);
		}
		i++;
		s = environ[i];
	}
	return (NULL);
}
/**
 * printenv - prints value
 * @environ: value printing
 * Return: NULL
 */
char *printenv(char **environ)
{
	char *s;
	int i;

	i = 0;
	s = environ[0];
	while (s != NULL)
	{
		_puts(s);
		i++;
		s = environ[i];
	}
	return (NULL);
}
/**
 * link_lister - function to create a linked list
 * @head: start of list
 * Return: 0
 */
int link_lister(cmd_finder **head)
{
	char *env, *hold;
	unsigned int i;
	cmd_finder *list;

	env = _getenv("PATH");
	i = 0;
	/* everything below this line creates a linked list of PATH */
	   /*   use the _getenv you made Sam */
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
