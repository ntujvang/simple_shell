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
