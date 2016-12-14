#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(int argc, char *argv[], char *env[])
{
	char *str, *token;
	size_t str_size, size;
	int i, status;
	pid_t pid, wpid;

	i = 0;
	size = 1024;
	str_size = 1;
	while (1)
	{
		printf(">=| ");
		str = NULL;
		str_size = getline(&str, &size, stdin);
		if (str_size == -1)
			perror("Conch: Error");
		token = strtok(str, " ");
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		argv[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Conch: Error");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("Conch");
		else
			wpid = wait(pid, &status);
	}
	return (0);
}
