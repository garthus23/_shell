#include "hsh.h"

/**
 * hsh_exec_cmd - exec a command
 * @arguments: array of arguments
 * @arr: an array
 * @st: a struct
 * Return: Nothing
 */

int hsh_exec_cmd(char *line, char **arguments, char **arr, char **copyenv)
{
	char *del = " \t\r\n\v\f";
	int i;
	struct stat st;


	i = 0;
	while (arr[i])
	{
		if (stat(arr[i], &st) == 0)
		{
			arguments[0] = arr[i];
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror(arguments[0]);
				break;
			}
		}
		i++;
	}
	if (execve(arguments[0], arguments, NULL) == -1)
	{
		perror(arguments[0]);
	}
	free_all(line, arguments, arr, copyenv);
	kill(getpid(), SIGTERM);
	return (0);
}
