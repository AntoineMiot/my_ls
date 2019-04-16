/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots d t r l R
*/
#include "include/my.h"

int check_arg_command(int ac, char **av)
{
    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'l' || av[i][1] == 'R'
            || av[i][1] == 'd' || av[i][1] == 'r' || av[i][1] == 't')
            return (2);
    }
    return (1);
}