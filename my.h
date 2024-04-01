/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #define MAX_PATH_LENGTH 1024
    #include <unistd.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <errno.h>
typedef struct list {
    char *name;
    char *value;
    struct list *next;
}set;

int display_prompt(void);
char *my_strdup(char *src);
int my_strcmp(char const *s1, char const *s2);
int cd_function(char *argv[]);
int my_strncmp(char *dest, char *src, int n);
size_t my_strlen(const char *str);
int my_putstr(char *str);
char *my_getenv(char *name);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int kora(const char *file, char *const argv[]);
int my_env(void);
char *take_before(char *str);
char *take_after(char *str);
int handle_cd_previous(char *str);
int handle_cd_home(char *str);
int handle_cd_directory(char *directory, char *str);
int is_whitespace(const char *str);
char *clean_str(char *str);
int count_parameters(char *args[]);
int change_directory(char *path);
void secour(int st);
int validate_cd_arguments(char *argv[]);
char *save_previous_dir(void);
void conditions(char *const argv[]);
int process_handling(pid_t pid, char *args[100]);
int setenv_custom(char *name, char *value, char *args[]);
void help(char *full_path, char *token, const char *file);
char **custom_realloc(char **tab, ssize_t size);
#endif
