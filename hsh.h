#ifndef HSH_H
#define HSH_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct format
{
	char *type;
	void (*f)();
} type_d;

void display_prompt(void);
char *hsh_readline(char **);
int hsh_exec_cmd(char **arguments, char **arr, struct stat *st);
int _strlen(char *);
char **splitstr(char *, char **);
char **array_PATH(char **env, char **buf, char**, int *path);
void free_arr(char**);
int builtin(char *str, char **environ);
void hsh_exit(char *str, char **arr, char **args, struct stat *st);
void hsh_env(char **environ);
void hsh_sigint();
char *_strtok( char *str, const char *delims, int *index);
int _strlen_strtok_delim(char *str, const char *delims, int *index);
int _check_following_delimeters(char *str, int *index, char *delims);
int len_env_path(char **env, int *path);
int _putchar(char);

#endif
