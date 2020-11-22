#include "hsh.h"

int len_env_path(char **env, int *path)
{
	int k, l;

	l = 0;
	for (*path = 0; strstr(env[*path], "PATH=") == NULL ; (*path)++)
	;
	for (k = 0; env[*path][k] != '\0'; k++)
	{
		if (env[*path][k] == ':')
		{
			l++;
		}
	}
	return (k);
}
