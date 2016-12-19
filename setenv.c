#include<stdlib.h>
#include<stdio.h>
#include"shell.h"
/**
 * _setenv - sets an environment variable to a new value
 * creates a new one if none found
 * @name: Name to variable to set/create
 * @value: Value for environmental varialbe
 * Return: returns a pointer to the new variable
 */
int _setenv(const char *name, const char *value)
{

	if((name == NULL) && value == NULL)
	{
		printf("Not enough input arguments\n");
		return (NULL);
	}

	if(_getenv(name, value) != NULL)
	{
		printf("The variable has been overwritten\n");
	}
	else
	{
		printf("The variable has been created\n");
	}
	return (NULL);
}
