/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include "my.h"

char *my_strdup(char *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
