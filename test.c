#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

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
/**** I don't know where to put this */
int main (int argc, char *argv[], char *envp[])
{
        char *string = "PWD";
        char *env;

        if (argc == 2)
	{
                env = _getenv(argv[1], envp);
                if (env != NULL)
                        printf("%s\n", env);
        }
        else
                printenv(envp);
}
/**End of I don't know where to put this*/

char *_getenv(const char *name, char **environ)
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

char *printenv(char **environ)
{
        char *s;
        int i;

        i = 0;
        s = environ[0];
        while (s != NULL)
        {
         	printf("%s\n", s);
                i++;
                s = environ[i];
        }
        return (NULL);
}
/**
 * _strcmp: compares two strings
 * @s1: string one to compare
 * @s2: string two to compare
 * Return: an integer less than 0 if s1 is found
 */

int _strcmp(const char *s1, char *s2)
{
        int i;

        i = 0;
	while (s1[i] != '\0')
        {
                if (s1[i] >  s2[i])
                        return (s1[i] - s2[i]);
                if (s1[i] < s2[i])
                        return (s1[1] - s2[i]);
                i++;
        }
        if (s1[i] == '\0' && s2[i] == '=')
                return (0);
}
