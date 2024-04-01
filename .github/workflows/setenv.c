/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

extern char **environ;

int count_parameters(char *args[])
{
    int c = 0;

    while (args[c] != NULL)
        c++;
    return c;
}
