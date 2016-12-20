#include "shell.h"

/**
 * _puts - function that prints out string
 * @str: first opperand
 * Return: string
 */
void _puts(char *str)
{
	while (*str != 0)
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
