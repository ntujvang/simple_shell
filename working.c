#include "shell.h"
/**
 * main - primary working area
 * @arg: number of arguments
 * @argv: array of arguments
 * Return: 1 for inifinite loop
 */
int main(__attribute__ ((unused)) int arg,
	 __attribute__ ((unused)) char *argv[])
{
	char *str;
	char **args;
	int status, hold;
	cmd_finder *head;
	size_t buffer;

	head = NULL;
	link_lister(&head);
	buffer = 0;
	while (1)
	{
		status = 0;
		_puts("Conch: ");
		/* created this thing it's own function because of */
		/*   data type errors */
		hold = getline(&str, &buffer, stdin);
		if (hold == EOF)
		{
			free(str);
			_puts("EOF\n");
			exit(98);
		}
		args = tokenize(str);
		/* this seems to be neccessary in order to keep */
		/* the loop running */
		status = builtinchecker(str, args);
		if (status == 0)
			status = check_me(str, head, args);
		if (status == 0)
			_puts("Command not found\n");
		free(args);
		free(str);
		_free(head);
	}
	return (0);
}
