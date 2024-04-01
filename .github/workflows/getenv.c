/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

extern char **environ;

char *my_getenv(char *name)
{
    if (name == NULL)
        return NULL;
    for (int i = 0; environ[i] != NULL; i++) {
        if (my_strncmp(name, environ[i], my_strlen(name)) == 0
    && environ[i][my_strlen(name)] == '=') {
            return (environ[i] + my_strlen(name) + 1);
        }
    }
    return NULL;
}
