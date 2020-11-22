#include "hsh.h"

/**
 * hsh_exec_cmd - exec a command
 * @arguments: array of arguments
 * @environ: extern char env
 * Return: Nothing
 */

int hsh_exec_cmd(char **arguments, char **arr, struct stat *st)
{

	int i;


	if (!arguments[0])
		kill(getpid(), SIGTERM);

	i = 0;
	while (arr[i])
	{
		if (stat(arr[i], st) == 0)
		{
			arguments[0] = arr[i];
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror(arguments[0]);
				free_arr(arguments);
				free_arr(arr);
				free(st);
				kill(getpid(), SIGTERM);
			}
		}
		i++;
	}
	if (execve(arguments[0], arguments, NULL) == -1)
	{
		perror(arguments[0]);
		free_arr(arguments);
		free_arr(arr);
		free(st);
		kill(getpid(), SIGTERM);
	}
	return (0);
}
