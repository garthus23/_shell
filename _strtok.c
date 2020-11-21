#include "hsh.h"

char *_strtok( char *str, const char *delims, int *index)
{
	int j, k;
	char *result;

	k = _strlen_strtok_delim(str, delims, index);

	if (k > 0)
	{
		result = malloc(sizeof(char) * k);
		k = 0;
		for (*index; str[*index] != '\0'; (*index)++)
		{
			for (j = 0; delims[j] != '\0'; j++)
			{
				if (str[*index] == delims[j] || str[*index + 1] == '\0')
				{
					if (str[*index + 1] == '\n')
						result[k] = str[(*index)];
					(*index)++;
					return(result);
				}
			}
			result[k] = str[(*index)];
			k++;
		}
	}
	exit (1);
}
