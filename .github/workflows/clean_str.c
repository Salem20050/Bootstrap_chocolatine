/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

void hayy(int *prevSpace, char *dest, int *j)
{
    if (!(*prevSpace)) {
        dest[*j] = ' ';
        (*j)++;
        (*prevSpace) = 1;
    }
}

char *clean_str(char *str)
{
    int n = strlen(str);
    int j = 0;
    int prevSpace = 1;
    char *dest = malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            hayy(&prevSpace, dest, &j);
        } else {
            dest[j] = str[i];
            j++;
            prevSpace = 0;
        }
    }
    while (j > 0 && (dest[j - 1] == ' ' || dest[j - 1] == '\t')) {
        j--;
    }
    dest[j] = '\0';
    return dest;
}
