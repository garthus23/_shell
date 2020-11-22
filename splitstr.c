#include "hsh.h"
/**
 * splitstr - create an array from a string
 * @str: a string
 * Return: an array
 **/

char **splitstr(char *str, char **ary)
{
	char *token;
	char *del = " \t";//\r\n\v\f";
	int i, j;
	int size = 8;
	int index = 0;

	if (!str)
		return (NULL);

	if (!ary)
		exit(1);


	i = 0;
	while (str[index] != '\0')
	{
		token = _strtok(str, del, &index);
		if (i >= size - 1)
		{
			size += size;
			ary = realloc(ary, sizeof(char *) * size);
		}
		ary[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (ary[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(ary[j]);
			free(ary);
		}
		ary[i] = token;
		_check_following_delimeters(str, &index, del);
		if (str[index + 1] == '\0')
			index++;
		i++;
	}
	return (ary);
}
