#include "hsh.h"

/**
 * array_PATH - concat path env to an array
 * @env: the env vars
 * @buf: the array
 * Return: a new 2D array
 **/

char **array_PATH(char **env, char **buf, char **arr, int *path)
{
	int j, k, l, index;
	char *delim = ":=";
	char *token;

	index = 0;
	token = _strtok(env[*path], delim, &index);
	token = _strtok(env[*path], delim, &index);
	j = 0;
	while (env[*path][index] != '\0')
	{
		token = _strtok(env[*path], delim, &index);
		arr[j] = malloc(sizeof(char) * (_strlen(token) + _strlen(*buf) + 2));
		for (k = 0; k < _strlen(token); k++)
			arr[j][k] = token[k];
		arr[j][k] = '/';
		k++;
		l = 0;
		for (; k <= (_strlen(token) + _strlen(*buf)) ; k++)
		{
			arr[j][k] = (*buf)[l];
			l++;
		}
		arr[j][k] = '\0';
		j++;
	}
	free(token);
	return (arr);
}
