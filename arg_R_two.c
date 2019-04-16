/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void recursiv(char **tab)
{
    struct stat s;

    for (int i = 0; tab[i] != 0; i++) {
        lstat(tab[i], &s);
        if (S_ISDIR(s.st_mode))
            file_arg_rr(tab[i]);
    }
}

void recursiv_two(char **tab)
{
    struct stat s;

    for (int i = 0; tab[i] != 0; i++) {
        lstat(tab[i], &s);
        if (S_ISDIR(s.st_mode))
            file_arg_rr_two(tab[i]);
    }
}

int disp_arg_rr(char *str, int z, char *filepath, int i)
{
    static int first = 0;

    if (i == 0 && first == 0) {;
        my_putstr(".:\n");
        first = 1;
    } else if (i == 0) {
        for (int j = 0; filepath[j] != '\0'; j++)
            my_putchar(filepath[j]);
        my_putstr(":\n");
    }
    my_putstr(str);
    if (i != z) {
        my_putchar(10);
        i++;
    }
    if (i == z)
        my_putchar(10);
}

int disp_arg_rr_two(char *str, int z, char *filepath, int i)
{
    if (i == 0) {
        for (int j = 0; filepath[j] != '\0'; j++)
            my_putchar(filepath[j]);
        my_putstr(":\n");
    }
    my_putstr(str);
    if (i != z) {
        my_putchar(10);
        i++;
    }
    if (i == z)
        my_putchar(10);
}

void file_arg_rr_scnd(char *filepath, int z, int i)
{
    char **tab;
    struct dirent *lecture;
    int j = 0;
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
            i = disp_arg_rr(lecture->d_name, z, filepath, i);
        }
    }
    tab[j] = '\0';
    closedir(rep);
    recursiv(tab);
}