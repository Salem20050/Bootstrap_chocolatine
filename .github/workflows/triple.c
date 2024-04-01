/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

int count_instructions(char **tab)
{
    int i = 0;
    
    for (i = 0; tab[i] != NULL; i++);
    return i;
}

char **str_to_word_virgule(char *str)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * strlen(str));
    char *token = strtok(str, ";");

    while (token != NULL) {
        tab[i] = token;
        i++;
        token = strtok(NULL, ";");
    }
    tab[i] = NULL;
    return tab;
}

char **str_to_word_space(char *str)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * strlen(str));
    char *token = strtok(str, " ");

    while (token != NULL) {
        tab[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tab[i] = NULL;
    return tab;
}

char ***array(char *str)
{
    char *tab = str_to_word_virgule(str);
    int c = count_instructions(tab);
    char ***luffy = malloc(sizeof(char **) * c);

    for (int i = 0; i < c; i++) {
        luffy[i] = str_to_word_space(tab[i]);
    }
    luffy[c] = NULL;
    return luffy;
}
