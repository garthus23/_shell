#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

char **array_PATH(char **env, char ***buf)
{
	int i, j;
	char *delim = ":=";
	char *token;
	char **arr;

	for (i = 0; strstr(env[i], "PATH=") == NULL ; i++);

	arr = malloc(sizeof(char *) * 15);

	token = strtok(env[i], delim);
	token = strtok(NULL, delim);

	j = 0;
	for (;token != NULL; token = strtok(NULL, delim))
	{
		arr[j] = malloc(sizeof(char) * 100);
		arr[j] = token;
		j++;
	}
/************************************************************************************************
*												*
*	Need to concatenate each elements of the new 2d array with first elements of the buffer *
*												*
*	have :  [0]  /bin/									*
*		[1]  /usr/bin									*
*												*
*	need :  [0]  /bin/ls									*
*		[1]  /usr/bin/ls								*
*												*
*************************************************************************************************/
	return(arr);
}

void create_exec_process(char **buf)
{
	int id, i;
	extern char** environ; 

	printf("%s\n", array_PATH(environ, &buf)[0]);


	id = fork();
	if (id == 0)
	{
		if (execve(buf[0], buf, environ) == -1)
		{
			perror("Execution Error");
		}
	}
	if (id != 0)
	{
		wait(NULL);
	}
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
