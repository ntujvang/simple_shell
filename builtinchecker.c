#include "shell.h"
/**
 * builtinchecker - function for checking built ins
 * @str: string going in
 * @args: the argument we want
 * Return: 0
 */
int builtinchecker(char *str, char **args)
{
	if (_strcmp(str, "exit") == 0)
		exitFunction(str, args);
	return (0);
}
/**
 * exitFunction - function to exit
 * @str: the string going in
 * @args: the argument we want
 * Return: 0
 */
void exitFunction(char *str, char **args)
{
	free(args);
	free(str);
	exit(98);
}
