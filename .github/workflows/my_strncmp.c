/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

int my_strncmp(char *dest, char *src, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        if (src[i] != dest[i]) {
            return src[i] - dest[i];
        }
    }
    return 0;
}
