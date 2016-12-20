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
	/* so far this work works, but it feels too short to be true */
	child = fork();
	if (child < 0)
		perror("Le Conch");
	else if (child == 0)
	{
		if (execve(command, args, environ) == -1)
			perror("Error");
	}
	else
		wait(&status);
	/* we want to return 1 so that it loops infinitly, although
	   it somehow works if we don't have return too because when fork
	   succeeds it also returns a positive # */
	return (1);
}

/* newest addition that checks against the path, but it's not working
   correctly */
int check_me(char *buffer, cmd_finder *h, char **args)
{
	char *temp;
	int i;

	i = 0;
	temp = malloc(1024);
	while (h != NULL)
	{
		/* gotta change these str functions */
		strcpy(temp, h->str);
		strcat(temp, "/");
		strcat(temp, buffer);
		h = h->next;
		if (access(temp, X_OK) == 0)
			i = execute(temp, args);
	}
	free(temp);
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
	   get anyhting to print Sam, because we were not getting rid of
	   new lines. Might want to check for tabs and returns too maybe? */
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
	/* hold is made for EOF testing, but that might be
	   the wrong way to do it */
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
		write(STDOUT_FILENO, "Le Conch: ", 10);
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
