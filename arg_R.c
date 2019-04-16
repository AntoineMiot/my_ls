/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void file_arg_rr(char *filepath)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    int i = 0;

    filepath = my_strcat(filepath, "/");
    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (z; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            z++;
    if (z == 0) {
        my_putstr(filepath);
        my_putstr(":\n");
        my_putchar(10);
    }
    closedir(rep);
    file_arg_rr_scnd(filepath, z, i);
}

void file_arg_rr_two_scnd(char *filepath, int z, int i)
{
    int j = 0;
    char **tab;
    struct dirent *lecture;
    DIR *rep;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    tab = malloc(sizeof(char*) * (z+1));
    for (j; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            tab[j] = malloc(sizeof(char)*(my_strlen(lecture->d_name)+1));
            tab[j] = my_strcat(filepath, lecture->d_name);
            j++;
            i = disp_arg_rr_two(lecture->d_name, z, filepath, i);
        }
    }
    tab[j] = '\0';
    closedir(rep);
    recursiv_two(tab);
}

void file_arg_rr_two(char *filepath)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    int i = 0;

    filepath = my_strcat(filepath, "/");
    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (z; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            z++;
    if (z == 0) {
        my_putstr(filepath);
        my_putstr(":\n");
        my_putchar(10);
    }
    closedir(rep);
    file_arg_rr_two_scnd(filepath, z, i);
}

void arg_rr_two(int ac, char **av)
{
    for (int i = 1; i != ac; i++)
        if (av[i][0] != '-')
            file_arg_rr_two(av[i]);
}

void arg_rr(int ac, char **av)
{
    int nb = -1;
    for (int m = 0; m != ac; m++)
        if (av[m][0] != '-')
            nb = nb + 1;
    if (nb == 0)
        file_arg_rr(".");
    else
        arg_rr_two(ac, av);
}