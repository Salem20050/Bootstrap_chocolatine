/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

extern char **environ;

void subtitute(char *args[100], char *token, char *input, int i)
{
    i = 0;
    token = strtok(input, " \n");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
    if (my_strcmp(args[0], "exit") == 0) {
        exit(0);
    }
}

int suppleant(pid_t pid, char *args[100])
{
    if (my_strcmp(args[0], "setenv") == 0) {
        my_env();
        return 0;
    }
    if (process_handling(pid, args) == -1) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
}

int prompt_loop(char *output, size_t len, char *args[100], pid_t pid)
{
    char *token;
    int i = 0;
    ssize_t read;
    char *input;

    while (1) {
        write(1, "$> ", 3);
        read = getline(&output, &len, stdin);
        input = clean_str(output);
        if (read == -1)
            exit(EXIT_SUCCESS);
        if (is_whitespace(input))
            continue;
        subtitute(args, token, input, i);
        if (my_strcmp(args[0], "cd") == 0) {
            cd_function(args);
            continue;
        }
        suppleant(pid, args);
    }
}

int display_prompt(void)
{
    char *input = NULL;
    size_t len = 0;
    char *args[100];
    pid_t pid;

    prompt_loop(input, len, args, pid);
    return 0;
}
