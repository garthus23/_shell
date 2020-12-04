#include "hsh.h"
/**
 * splitstr - create an array from a string
 * @str: a string
 * @ary: an array
 * Return: an array
 **/

int splitstr(char *str, char **ary)
{
	char *token = NULL;
	char *del = " \t\r\n\v\f";
	int i, j;
	int size = 8;
	int index = 0;


	i = 0;
	while (str[index] != '\0')
	{
		_check_following_delimeters(str, &index, del);
		token = malloc(sizeof(char) * 100);
		_strtok(token, str, del, &index);
		ary[i] = malloc(sizeof(char) * 100);
		if (ary[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(ary[j]);
			free(ary);
		}
		for (j = 0; token[j] != '\0'; j++)
			ary[i][j] = token[j];
		ary[i][j] = '\0';
		_check_following_delimeters(str, &index, del);
		i++;
		free(token);
	}
	ary[i] = NULL;
	return (0);
}
