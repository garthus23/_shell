#include "hsh.h"


/**
 * main - main function of the hsh shell
 * @argc: number of arguments
 * @argv: char table of arguments
 * @envp: externe char environ
 * Return: 0 when it works
 **/

int main(int argc, char *argv[], char *envp[])
{
	int path = 0, k;
	struct stat *st;
	char **args;
	char **arr;
	char *line;
	int status = 1;
	pid_t id;

	(void)argc;
	(void)argv;


	k = len_env_path(envp, &path);
	arr = malloc(sizeof(char *) * k);
	st = malloc(sizeof(struct stat));
	args = malloc(sizeof(char *) * 8);

	while (status)
	{
		display_prompt();
		hsh_readline(&line);
		hsh_exit(line, arr, args, st);
		id = fork();
		if (id == 0)
		{
			splitstr(line, args);
			array_PATH(envp, args, arr, &path);
			builtin(args[0], envp);
			hsh_exec_cmd(args, arr, st);
			free(line);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
