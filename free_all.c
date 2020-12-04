#include "hsh.h"

int free_all(char *line, char **arguments, char **arr, char **copyenv)
{
	free(line);
	free_arr(arguments);
	free_arr(arr);
	free_arr(copyenv);

	return (1);
}
