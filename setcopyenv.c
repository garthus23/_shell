#include "hsh.h"


int setcopyenv(char **envp, char **copyenv)
{
	int i, j;

	i = 0;
	while (envp[i])
	{
		copyenv[i] = malloc(sizeof(char) * (strlen(envp[i])+2));
		for(j = 0; envp[i][j] != '\0'; j++)
		{
			copyenv[i][j] = envp[i][j];
		}
		copyenv[i][j] = '\0';
		i++;
	}
	copyenv[i] = NULL;

	return (1);
}
