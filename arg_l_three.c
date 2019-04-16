/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void check_slash(char **av, int i)
{
    if (av[i][my_strlen(av[i])] != 92) {
        total_block(my_strcat(av[i], "/"));
        array_file(my_strcat(av[i], "/"));
    } else {
        total_block(av[i]);
        array_file(av[i]);
    }
}

void folders(char *str, int type)
{
    if (type == 4)
        my_putchar('d');
    else
        my_putchar('-');
}

void permission(char *str, char *name, int type)
{
    folders(str, type);
    utilisa(str);
    group(str);
    other(str);
    nlink(str);
    time_modif(str);
    my_putstr(name);
    my_putchar(10);
}