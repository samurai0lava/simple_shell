#ifndef _SHELL_
#define _SHELL_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

char *_getenv(const char *envar);
int _execute(char **args);
int _begin(char **args);
char *get_thepath(char *cmd);
char **split_theline(char *theline);
char *read_theline(void);
void _loop(void);

#define MAX_BUFFER_SIZE 1024
ssize_t my_own_getline(char **lineptr, size_t *n, FILE *stream);
ssize_t read_input(char *buffer, FILE *stream);
int find_newline(char *buffer, int start, int end);
void copy_to_line(char *buffer, int start, int end, char *line);

char *_strtok(char *thestring, const char *delim);
char *find_next_delim(char *str, const char *delim);
char *find_next_token(char *str, const char *delim);
int is_delimiter(char ch, const char *delim);

int _putchar(char m);
int _strcmp(const char *str1, char *str2);
int _strlen(const char *str);
char *_strcat(char *destr, char *sourstr);
char *_strcpy(char *destr, char *sourstr);

int _cd(char **args);
int _out(char **args);
int _env(void);


#endif
