/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void permission(char *str, char *name, int type);
void file_arg_rrl(char *filepath);
void total_block(char *filepath);

void recursiv_rrl(char **tab)
{
    struct stat s;

    for (int i = 0; tab[i] != 0; i++) {
        lstat(tab[i], &s);
        if (S_ISDIR(s.st_mode)) {
            my_putchar(10);
            file_arg_rrl(tab[i]);
        }
    }
}

void file_arg_rrl_tab(char *filepath, int z)
{
    int j = 0;
    struct dirent *lecture;
    DIR *rep;
    char **tab;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    tab = malloc(sizeof(char*) * (z+1));
    for (; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            tab[j] = malloc(sizeof(char)*(my_strlen(lecture->d_name)+1));
            tab[j] = my_strcat(filepath, lecture->d_name);
            j++;
            permission(my_strcat(filepath, lecture->d_name),
            lecture->d_name, lecture->d_type);
        }
    }
    tab[j] = '\0';
    closedir(rep);
    recursiv_rrl(tab);
}

void file_arg_rrl(char *filepath)
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
    closedir(rep);
    file_arg_rrl_putstr(filepath);
    total_block(filepath);
    file_arg_rrl_tab(filepath, z);
}

void arg_rrl_two(int ac, char **av)
{
    for (int i = 1; i != ac; i++)
        if (av[i][0] != '-')
            file_arg_rrl(av[i]);
}

void arg_rrl(int ac, char **av)
{
    int nb = -1;
    for (int m = 0; m != ac; m++)
        if (av[m][0] != '-')
            nb = nb + 1;
    if (nb == 0) {
        file_arg_rrl(".");
    } else
        arg_rrl_two(ac, av);
}