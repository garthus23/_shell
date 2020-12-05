#include "hsh.h"


/**
 * main - main function of the hsh shell
 * @argc: number of arguments
 * @argv: char table of arguments
 * @envp: externe char environ
 * Return: 0 when it works
 **/

int main(void)
{
	int path = 0, k, i;
	size_t size = 0;
	char **args, **arr, **copyenv;
	char *line;
	char *del = " \t\r\n\v\f";
	int status = 1;
	pid_t id;

	k = len_env_path(environ, &path);
	copyenv = malloc(sizeof(char *) * 100);
	line = malloc(sizeof(char) * 100);
	arr = calloc(100, sizeof(char *));
	args = calloc(100, sizeof(char *));
	size = 100;

	setcopyenv(environ, copyenv);

	while (status)
	{
		display_prompt();
		hsh_readline(&line, &size);
		splitstr(line, args);
		if(hsh_exit(line) == 1)
			break;
		if (_isempty(line, del) == 0 && builtin(args, copyenv) == 0)
			id = fork();
		if (id == 0)
		{
			array_PATH(copyenv, args, arr, &path);
			hsh_exec_cmd(line, args, arr, copyenv);
		}
		else
		{
			wait(NULL);
		}
	}
	free_all(line, args, arr, copyenv);
	return (0);
}
