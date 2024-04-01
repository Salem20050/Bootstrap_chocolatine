/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** This is a function my_putstr.
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int x;

    for (x = 0; str[x] != '\0'; x++) {
        my_putchar(str[x]);
    }
    return 0;
}
