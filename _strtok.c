#include "hsh.h"

/**
 * _strtok - cut a string
 * @str: a string
 * @delims: a delimiters
 * @index: an index
 * Return: result
 **/
char *_strtok(char *result, char *str, const char *delims, int *index)
{
	int j, k;

	k = _strlen_strtok_delim(str, delims, index);

	if (k > 0)
	{
//		result = malloc(sizeof(char) * (k + 1));
		k = 0;
		for (; str[*index] != '\0'; (*index)++)
		{
			for (j = 0; delims[j] != '\0'; j++)
			{
				if (str[*index] == delims[j])
				{
					(*index)++;
					result[k] = '\0';
					return (result);
				}
			}
			result[k] = str[(*index)];
			k++;
		}
		result[k] = '\0';
		return (result);
	}
	exit(1);
}
