#ifndef HSH_H
#define HSH_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

typedef struct format
{
	char *type;
	void (*f)();
} type_d;

void display_prompt(void);
char *hsh_readline(char **line, size_t *size);
int hsh_exec_cmd(char *line, char **arguments, char **arr, char **copyenv);
int _strlen(char *);
int splitstr(char *, char **);
int array_PATH(char **env, char **buf, char**, int *path);
void free_arr(char**);
int free_all(char *line, char **arguments, char **arr, char **copyenv);
int builtin(char **args, char **environ);
int hsh_exit(char *str);
void hsh_env(char **environ, char **args);
void hsh_sigint();
char *_strtok( char * result, char *str, const char *delims, int *index);
int _strlen_strtok_delim(char *str, const char *delims, int *index);
int _check_following_delimeters(char *str, int *index, char *delims);
int len_env_path(char **env, int *path);
int setcopyenv(char **envp, char **copyenv);
int _isempty(char *str, char *del);
int _putchar(char);

#endif
