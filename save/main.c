#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

char **array_PATH(char **env, char ***buf)
{
	int i, j, k, l, len_token, len_buf, len_tot;
	char *delim = ":=";
	char *token;
	char **arr;


	for (i = 0; strstr(env[i], "PATH=") == NULL ; i++);

	arr = malloc(sizeof(char *) * 15);

	token = strtok(env[i], delim);
	token = strtok(NULL, delim);
	
	len_buf = strlen(**buf);

	for (j = 0;token != NULL; token = strtok(NULL, delim))
	{
		len_token = strlen(token);
		len_tot =(len_token + len_buf);
		arr[j] = malloc(sizeof(char) * 1000);
		for (k = 0; k < len_token; k++)
			arr[j][k] = token[k];
		arr[j][k] = '/';
		k++;
		l = 0;
		for (; k <= len_tot ; k++)
		{
			arr[j][k] = (**buf)[l];
			l++;
		}
		arr[j][k] = '\0';
		j++;
	}
	return(arr);
}

void create_exec_process(char **buf)
{
	int id, i;
	extern char** environ; 
	char **arr = array_PATH(environ, &buf);

	for(i = 0; arr[i] != NULL; i++)
		printf("%s\n", arr[i]);

/********************************************************
 *	Need to implement the stat command and put 	*
 *	the 2d Array in a linkedlist for stat.		*
 *							*
 *							*
 ********************************************************

	id = fork();
	if (id == 0)
	{
		if (stat(buf[0]) == 0)
		{
			if (execve(buf[0], buf, environ) == -1)
			{
				perror("Execution Error");
			}
		}
		if (stat(buf[0]) != 0)
		{
			if(execve(array_PATH(environ, &buf), buf, environ) == -1)
			{
				perror("Execution Error");
			}
		}
	}
	if (id != 0)
	{
		wait(NULL);
	}**/
}

char **parse_line(char *buf)
{
	int i = 0;
	char **arr;
	char *delim = " :\n\t";
	char *token = strtok(buf, delim);

	arr = malloc(1000);
	for(;token != NULL; token = strtok(NULL, delim))
	{
		arr[i] = malloc(1000);
		arr[i] = token;
		i++;
	}

	return (arr);
}

int main(void)
{
	int i;
	char *buf[1024];
	size_t size=1024;

	while (true)
	{
			write(1, "£ ", 3);
			getline(buf, &size, stdin);
			create_exec_process(parse_line(*buf));
	}
}
