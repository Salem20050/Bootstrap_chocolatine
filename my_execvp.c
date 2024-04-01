/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

extern char **environ;

int execute_file(const char *file, char *const argv[])
{
    pid_t pid = fork();
    int st = 0;

    if (pid == 0) {
        execve(file, argv, environ);
        conditions(argv);
    } else if (pid > 0) {
        waitpid(pid, &st, WUNTRACED);
        secour(st);
    } else {
        return -1;
    }
    return 0;
}

char *construct_full_path(char *dir, const char *file)
{
    size_t dir_len = my_strlen(dir);
    size_t file_len = my_strlen(file);
    char *full_path = malloc((dir_len + file_len + 2) * sizeof(char));

    help(full_path, dir, file);
    return full_path;
}

int search_executable(const char *file, char *const argv[])
{
    char *path = my_getenv("PATH");
    char *path_copy = my_strdup(path);
    char *token = strtok(path_copy, ":");
    char *full_path;
    int st = 0;
    int result;

    while (token != NULL) {
        full_path = construct_full_path(token, file);
        if (access(full_path, X_OK) == 0) {
            result = execute_file(full_path, argv);
            free(full_path);
            free(path_copy);
            return result;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return -1;
}

int kora(const char *file, char *const argv[])
{
    if (access(file, X_OK) == 0) {
        return execute_file(file, argv);
    } else {
        return search_executable(file, argv);
    }
}
