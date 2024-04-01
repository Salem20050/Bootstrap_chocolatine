/*
** EPITECH PROJECT, 2023
** MY_STRCMP
** File description:
** Return a value n when two strings are equal or not
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int value = 0;

    while (s1[i] == s2[i]
    && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    value = s2[i] -s1[i];
    return value;
}
