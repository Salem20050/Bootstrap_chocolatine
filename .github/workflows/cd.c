/*
** EPITECH PROJECT, 2024
** cd function
** File description:
** cd function
*/

#include "my.h"

char *prev_dir;
char *save_previous_dir(void)
{
    char *str = malloc(sizeof(char) * 1000);

    if (getcwd(str, MAX_PATH_LENGTH) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    return str;
}

int handle_cd_operation(char *argv[])
{
    char *str = save_previous_dir();

    if (argv[1] != NULL && my_strcmp(argv[1], "-") == 0) {
        return handle_cd_previous(str);
    } else if (argv[1] == NULL) {
        return handle_cd_home(str);
    } else {
        return handle_cd_directory(argv[1], str);
    }
}

int cd_function(char *argv[])
{
    int result;

    result = validate_cd_arguments(argv);
    if (result != 0) {
        return result;
    }
    result = handle_cd_operation(argv);
    return result;
}
