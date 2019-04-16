/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

int disp_arg_rrl(char *str, int z, char *filepath, int i)
{
    static int first = 0;

    if (i == 0 && first == 0) {
        my_putstr(".:\n");
        first = 1;
    }
}

void file_arg_rrl_putstr(char *filepath)
{
    int static first = 0;

    if (first == 0) {
        my_putstr(".:\n");
        first = 1;
    } else {
        my_putstr(filepath);
        my_putstr(":\n");
    }
}