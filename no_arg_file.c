/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void just_file_solo(char *filepath)
{
    struct dirent *lecture;
    DIR *rep;
    int i = 0;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (int z; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            no_arg_color_disp(lecture->d_name, lecture->d_type);
            z = no_arg_disp_space(z, i);
        }
    }
    closedir(rep);
}

void just_file_putchar(int ac, int i)
{
    if (i + 1 != ac)
        my_putchar('\n');
}

void just_file(int ac, char **av)
{
    if (ac == 2)
        just_file_solo(av[1]);
    if (ac > 2) {
        for (int i = 1; i != ac; i++) {
            my_putstr(av[i]);
            my_putstr(":\n");
            just_file_solo(av[i]);
            just_file_putchar(ac, i);
        }
    }
}