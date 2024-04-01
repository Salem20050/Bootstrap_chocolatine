/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** count letters
*/

#include "my.h"

size_t my_strlen(const char *str)
{
    const char *s = str;

    while (*s)
        ++s;
    return s - str;
}
