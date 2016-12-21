#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
typedef struct commands
{
	char *str;
	struct commands *next;
}cmd_finder;
int execute(const char *command, char **args);
int check_me(char *buffer, cmd_finder *h, char **args);
char **tokenize(char *str);
char *_getline(void);
void _puts(char *str);
int _putchar(char c);
char *_getenv(const char *name);
int _strcmp(const char *s1, char *s2);
char *printenv(char **environ);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
int link_lister(cmd_finder **head);
int builtinchecker(char *str, char **args);
void exitFunction(int status, char *str, char **args);
char *_strcat(char *dest, char *src);
#endif
