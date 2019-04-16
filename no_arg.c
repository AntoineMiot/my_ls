/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

int no_arg_disp_space(int z, int i)
{
    if (z != i - 1) {
        my_putstr("\n");
        z++;
    }
    return (z);
}

void no_arg_color_disp(char *str, int type)
{
    struct stat s;

    if (type == 4) {
        my_putstr("\033[34m");
        my_putstr(str);
        my_putstr("\033[0m");
    } else {
        stat(str, &s);
        if (s.st_mode & S_IXUSR || s.st_mode & S_IXOTH || s.st_mode & S_IXGRP) {
            my_putstr("\033[32m");
            my_putstr(str);
            my_putstr("\033[0m");
        } else
            my_putstr(str);
    }
}

void no_arg(void)
{
    struct dirent *lecture;
    DIR *rep;
    int i = 0;

    rep = opendir(".");
    for (i; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            i++;
    closedir(rep);
    rep = opendir(".");
    for (int z; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            no_arg_color_disp(lecture->d_name, lecture->d_type);
            z = no_arg_disp_space(z, i);
        }
    }
    closedir(rep);
}