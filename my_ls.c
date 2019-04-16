/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots d t r l R
*/
#include "include/my.h"

int distrib_return_option_valor_two(char av, int option)
{
    static int first_d = 0;
    static int first_r = 0;
    static int first_tt = 0;

    if (av == 'd' && first_d == 0) {
        option = option + 4;
        first_d = 1;
    }
    if (av == 'r' && first_r == 0) {
        option = option + 5;
        first_r = 1;
    }
    if (av == 't' && first_tt == 0) {
        option = option + 6;
        first_tt = 1;
    }
    return (option);
}

int distrib_return_option_valor(char av, int option)
{
    static int first_l = 0;
    static int first_R = 0;

    if (av == 'l' && first_l == 0) {
        option = option + 1;
        first_l = 1;
    }
    if (av == 'R' && first_R == 0) {
        option = option + 2;
        first_R = 1;
    }
    return (option);
}

int distrib_two(int ac, char **av, int option)
{
    switch (option) {
    case 1 :
        arg_l(ac, av);
        break;
    case 2 :
        arg_rr(ac, av);
        break;
    case 3 :
        arg_rrl(ac, av);
        break;
    case 4 :
        arg_d(ac, av);
        break;
    case 5 :
        arg_r(ac, av);
        break;
    case 6 :
        arg_tt(ac, av);
        break;
    }
}

void distrib(int ac, char **av)
{
    int option = 0;

    for (int i = 1; i != ac && av[i][0] == '-'; i++) {
        for (int j = 1; av[i][j] != '\0'; j++) {
            option = distrib_return_option_valor(av[i][j], option);
            option = distrib_return_option_valor_two(av[i][j], option);
        }
    }
    distrib_two(ac, av, option);
}

int main(int ac, char **av)
{
    int checker = 0;

    if (ac == 1)
        no_arg();
    else if (ac > 1) {
        if (check_arg_command(ac, av) == 2) {
            distrib(ac, av);
        } else if (check_arg_command(ac, av) == 1) {
            just_file(ac, av);
        }
    }
    return (0);
}