/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

void conditions(char *const argv[])
{
    if (errno == EACCES) {
        write(2, argv[0], my_strlen(argv[0]));
        write(2, ": Permission denied.\n", 21);
    }
    if (errno == ENOEXEC) {
        write(2, argv[0], my_strlen(argv[0]));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
    }
}
