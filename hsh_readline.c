#include "hsh.h"

/**
 * hsh_readline - readline from stdin
 * @line: an array
 * Return: nothing
 **/

char *hsh_readline(char **line, size_t *size)
{
//	*line = malloc(sizeof(char) * 100);

	if (getline(line, size, stdin) == EOF)
		exit(0);

	return (*line);
}
