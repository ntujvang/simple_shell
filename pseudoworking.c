#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int main(int arg, char *argv[])
{
	char *str, *temp;
	char **args;
	int run, i, j;
	size_t hold, buffer;
	pid_t child, parent;
/*	char cmds[] =
	{
		"ls"
		}; */

	i = 0;
	str = NULL;
	run = 1;
	buffer = 1024;
	while (run)
	{
		printf("Le Conch: ");
		hold = getline(&str, &buffer, stdin);
		if (hold == EOF)
		{
			printf("EOF\n");
			exit(0);
		}
		args = malloc(1024);
		temp = strtok(str, "\n ");
		while (temp != NULL)
		{
			args[i] = temp;
			temp = strtok(NULL, "\n ");
			i++;
			printf("%s", args[i]);
		}
		args[i] = NULL;
		/* something is wrong with the forking here that is
		   closing the loop */
		child = fork();
		if (child == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
/*			printf("args[0] is %s\n", args[0]); */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
			}
		}
		else
				wait(&run);

		free(args);
		free(temp);
	}
	return (EXIT_SUCCESS);
}
