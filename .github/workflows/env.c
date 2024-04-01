/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

extern char **environ;

int my_env(void)
{
    int i = 0;

    while (environ[i] != NULL) {
        my_putstr(environ[i]);
        my_putstr("\n");
        i++;
    }
    return 0;
}

// void display_env(set *node)
// {
//     if (node == NULL) {
//         my_putstr("Environment list is empty\n");
//         return;
//     }

//     while (node != NULL) {
//         printf("%s=%s\n", node->name, node->value);
//         node = node->next;
//     }
// }
