/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

int is_whitespace(const char *str)
{
    while (*str != '\0') {
        if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r') {
            return 0;
        }
        str++;
    }
    return 1;
}
