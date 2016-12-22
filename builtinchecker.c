#include "shell.h"
/**
 * builtinchecker - function for checking built ins
 * @str: string going in
 * @args: the argument we want
 * @head: linked list
 * Return: 0
 */
int builtinchecker(char *str, char **args, cmd_finder *head)
{
	if (strcmp(str, "exit") == 0)
		exitFunction(str, args, head);
	return (0);
}
/**
 * exitFunction - function to exit
 * @str: the string going in
 * @args: the argument we want
 * @head: linked list
 * Return: 0
 */
void exitFunction(char *str, char **args, cmd_finder *head)
{
	_free(head);
	free(args);
	free(str);
	exit(98);
}
