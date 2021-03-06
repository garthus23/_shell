#include "hsh.h"

/**
 * hsh_exit - exit builtin function
 * @str: an input string
 * @arr: an array
 * @args: an array
 * @st: a struct
 * Return: nothing
 **/

int hsh_exit(char *str)
{
	char *result = "exit";
	int ex = 1;
	int i;

	if (_strlen(str) >= 1)
	{
		for (i = 0; result[i] != '\0'; i++)
		{
			if (str[i] != result[i])
			{
				ex = 0;
				break;
			}
		}
		if (ex == 1)
		{
			return (1);
		}
	}
	return (0);
}
