#include "hsh.h"

/**
 * _check_following_delimeters - check for multiple delimeters
 * @str: a string
 * @index: an index
 * @delims: delimeters
 * Return: 0
 **/

int _check_following_delimeters(char *str, int *index, char *delims)
{
	int del;
	int i;

	for (del = 1; del != 0 ; (*index)++)
	{
		for (i = 0; delims[i] != '\0'; i++)
		{
			if (str[*index] == delims[i])
			{
				del = 1;
				break;
			}
			else
			{
				del = 0;
			}
		}
		if (del == 0)
			return (0);
	}
	return (0);
}
