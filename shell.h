#ifndef SHELL_H
#define SHELL_H
typedef struct commands
{
	char *str;
	struct commands *next;
}cmd_finder;
void _puts(char *str);
int _putchar(char c);
char *_getenv(const char *name);
int _strcmp(const char *s1, char *s2);
char *printenv(char **environ);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
int link_lister(cmd_finder **head);
void exitFunction(int status, char *str, char **args);
#endif
