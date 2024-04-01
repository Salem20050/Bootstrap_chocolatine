/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 1)
    return 84;
    display_prompt();
    return 0;
}
