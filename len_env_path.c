#include "hsh.h"

/**
 * len_env_path - len of env path
 * @env: environnement variable
 * @path: an index
 * Return: an int
 **/
int len_env_path(char **env, int *path)
{
	int k = 0, l;

	l = 0;
	for (*path = 0; env[*path] != NULL  ; (*path)++)
	{
		if (strstr(env[*path], "PATH=/") != NULL)
			break;
	}

	if (env[*path] != NULL)
		for (k = 0; env[*path][k] != '\0'; k++)
		{
			if (env[*path][k] == ':')
			{
				l++;
			}
		}
	return (k);
}
