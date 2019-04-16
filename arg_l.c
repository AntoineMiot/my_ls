/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void array_file(char *filepath)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    char **tab;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (int j = 0; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            permission(my_strcat(filepath, lecture->d_name),
            lecture->d_name, lecture->d_type);
            j++;
        }
    }
    closedir(rep);
}

void total_block(char *filepath)
{
    struct stat s;
    struct dirent *lecture;
    DIR *rep;
    int block = 0;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (int j = 0; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.' && lecture->d_name == NULL)
            exit(84);
        if (lecture->d_name[0] != '.') {
            stat(my_strcat(filepath, lecture->d_name), &s);
            block = block + s.st_blocks;
        }
    }
    closedir(rep);
    my_putstr("total ");
    my_put_nbr(block/2);
    my_putchar(10);
}

int arg_l_two_scnd(int ac, int space)
{
    if (space != ac - 2) {
        my_putchar('\n');
        space++;
    }
    return (space);
}

void arg_l_two(int ac, char **av)
{
    int space = 1;

    for (int i = 1; i != ac; i++) {
        if (av[i][0] != '-') {
            my_putstr(av[i]);
            my_putstr(":\n");
            check_slash(av, i);
            space = arg_l_two_scnd(ac, space);
        }
    }
}

void arg_l(int ac, char **av)
{
    int nb = -1;
    int i = 1;

    for (int m = 0; m != ac; m++)
        if (av[m][0] != '-')
            nb = nb + 1;
    for (i; i != ac; i++)
        if (av[i][0] != '-')
            break;
    if (nb == 0) {
        total_block("./");
        array_file("./");
    } else if (nb == 1) {
        check_slash(av, i);
    } else
        arg_l_two(ac, av);
}