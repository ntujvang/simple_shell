#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a new string which is a duplicate
 * of string str
 * @str: string to copy
 * Return: pointer to copy of string
 */

char *_strdup(char *str)
{
	char *copy_string;
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
		;
	copy_string = malloc(i * sizeof(char));
	for (j = 0; str[j] != '\0'; j++)
		copy_string[j] = str[j];
	return (copy_string);
}

#include <stdio.h>
#include <stdlib.h>

/**
 *str_concat - returns a pointer that contains a string
 * that is a combination of two strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to the concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	char *str;
	int i, j, k;

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	str = malloc((i + j) * sizeof(*str));
	for (k = 0; s1[k] != '\0'; k++)
		str[k] = s1[k];
	j = 0;
	while (s2[j] != '\0')
	{
		str[k] = s2[j];
		j++;
		k++;
	}
	return (str);
}
