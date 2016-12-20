#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
extern char **environ;

int execute(const char *command, char **args)
{
	pid_t child;
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
	/* we want to return 1 so that it loops infinitly, although
	   it somehow works if we don't have return too because when fork
	   succeeds it also returns a positive # */
	return (1);
}

int check_me(char *buffer, cmd_finder *h, char **args)
{
	char *temp;
	int i;

	if (buffer[0] == '/')
	{
		if (access(buffer, X_OK) == 0)
		{
			i = execute(buffer, args);
			return (1);
		}
		return (0);
	}

	i = 0;
	temp = malloc(100);
	while (h != NULL)
	{
		/* gotta change these str functions */
		strcpy(temp, h->str);
		strcat(temp, "/");
		strcat(temp, buffer);
 		if (access(temp, X_OK) == 0)
		{
			i = execute(temp, args);
			break;
		}
		h = h->next;
	}
	free(temp);
	if (h == NULL)
		return (0);
	return (1);
}


char **tokenize(char *str)
{
	int buffer, i;
	char **token;
	char *hold;

	i = 0;
	buffer = 1024;
	token = malloc(buffer * sizeof(char *));
	if (token == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	/* (" \n" was the primary reason why we couldn't
	   get anyhting to print */
	hold = strtok(str, " \n");
	while (hold != NULL)
	{
		token[i] = hold;
		i++;
		hold = strtok(NULL, " \n");
	}
	token[i] = NULL;
	return (token);
}

char *_getline(void)
{
	char *str;
	ssize_t buffer, hold;

	buffer = 0;
	hold = getline(&str, &buffer, stdin);
	if (hold == EOF)
	{
		printf("EOF\n");
		exit(0);
	}
	return (str);
}

int main(int arg, char *argv[])
{
	char *str;
	char **args;
	int status;
	cmd_finder *head;

	head = NULL;
	link_lister(&head);
	status = 1;
	while (status)
	{
		write(STDOUT_FILENO, "Conch: ", 10);
		/* created this thing it's own function because of
		   data type errors */
		str = _getline();
		args = tokenize(str);
		/* this seems to be neccessary in order to keep
		   the loop running */
		status = check_me(str, head, args);
		free(args);
		free(str);
	}
	return (0);
}
