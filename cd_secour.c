/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishel
*/

#include "my.h"

extern char *prev_dir;
char *save_previous_dir(void);

void help(char *full_path, char *token, const char *file)
{
    my_strcpy(full_path, token);
    my_strcat(full_path, "/");
    my_strcat(full_path, file);
}

int change_directory(char *path)
{
    char *str = save_previous_dir();

    if (chdir(path) == 0) {
        prev_dir = my_strdup(str);
        return 0;
    } else {
        return -1;
    }
}

int validate_cd_arguments(char *argv[])
{
    if (count_parameters(argv) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    }
    return 0;
}
