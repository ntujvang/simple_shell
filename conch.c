#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

typedef void (*sighandler_t)(int);
char c = '\0';

void handle_signal(int signo)
{
	printf("\nSpeak to Conch:");
	fflush(stdout);
}

int main(int argc, char *argv[], char *envp[])
{
	char *str, *token;
	size_t array_size, size;

	size = 1024;
	array_size = 1;
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	str = (char *) malloc(size);
	printf("\nWelcome to Conch:");
	while(c != EOF)
	{
		c = getline(&str, &size, stdin);
		if (array_size == -1)
			printf("Error\n");
		else
			printf("%s", str);
		token = strtok (str, " ,.-");
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok (NULL, " ,.-");
		}
	}
	if(c == '\n')
	{
		printf("Speak to Conch:");
	}
	printf("\n");
	return 0;
}
