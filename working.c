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
	int status;
	cmd_finder *head;

	head = NULL;
	link_lister(&head);

	while (1)
	{
		status = 0;
		_puts("Conch: ");
		/* created this thing it's own function because of */
		/*   data type errors */
		str = _getline();
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
	}
	return (0);
}
