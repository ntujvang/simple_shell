#include "shell.h"
/**
 * execute - function to execute commands
 * @command: command running
 * @args: arg we want to run
 * Return: 1 for inifinte loop
 */
int execute(const char *command, char **args)
{
	int child;
	int status;

	if (args[0] == NULL)
		return (1);
	child = fork();
	if (child < 0)
		perror("Conch");
	else if (child == 0)
	{
		execve(command, args, environ);
		perror("Error"); /* child should never get past execve */
	}
	else
		wait(&status);
	return (1);
}
