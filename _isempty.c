#include "hsh.h"

int _isempty(char *str, char *del)
{
	int i, j, empty;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; del[j] != '\0'; j++)
			{
				if (str[i] == del[j])
				{
					empty = 1;
					break;
				}
				else
				{
					empty = 0;
				}
			}
			if (empty == 0)
				return (empty);
		}
	}
	return (empty);
}
