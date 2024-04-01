/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

extern char *prev_dir;

void secour(int st)
{
    if (st == 139 || st == 11) {
        write(2, "Segmentation fault\n", 19);
    }
}

int handle_cd_previous(char *str)
{
    if (chdir(prev_dir) == -1) {
        perror("chdir");
        return 84;
    } else {
        prev_dir = my_strdup(str);
    }
    return 0;
}

int handle_cd_home(char *str)
{
    if (chdir(my_getenv("HOME")) == -1) {
        return 84;
    } else {
        prev_dir = my_strdup(str);
    }
    return 0;
}

int handle_cd_directory(char *directory, char *str)
{
    if (change_directory(directory) == -1) {
        if (errno == ENOTDIR) {
            write(2, directory, my_strlen(directory));
            write(2, ": Not a directory.\n", 19);
        }
        if (errno == ENOENT) {
            write(2, directory, my_strlen(directory));
            write(2, ": No such file or directory.\n", 29);
        }
    }
    return 0;
}
