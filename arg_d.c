/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void arg_d(int ac, char **av)
{
    int i = 1;
    int z;
    struct dirent *lecture;
    DIR *rep;

    for (i; i != ac; i++)
        if (av[i][0] != '-')
            break;
    z = i;
    if (z == ac)
        my_putstr(".\n");
    for (z; z != ac; z++) {
        my_putstr(av[z]);
        my_putchar(10);
    }
}