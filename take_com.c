/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

char *take_before(char *str)
{
    int i = 0;
    char *xr = malloc(sizeof(char) * strlen(str));

    while (str[i] != '=') {
        xr[i] = str[i];
        i++;
    }
    xr[i] = '\0';
    return xr;
}

int find_eq(char *str)
{
    int i;

    for (i = 0; str[i] != '='; i++) {
    }
    return i;
}

char *take_after(char *str)
{
    int i = find_eq(str) + 1;
    int x = 0;
    char *xr = malloc(sizeof(char) * strlen(str));

    while (str[i] != '\0') {
        xr[x] = str[i];
        i++;
        x++;
    }
    xr[i] = '\0';
    return xr;
}

int process_handling(pid_t pid, char *args[100])
{
    if (kora(args[0], args) == -1) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 21);
        return 0;
    }
    return 0;
}
