/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void swap_elem_file(char **tbl, long int *tbl_int, int index1, int index2)
{
    int tempo = tbl_int[index1];
    char *tempo_str = tbl[index1];

    if (tbl_int[index1] > tbl_int[index2]) {
        tempo = tbl_int[index1];
        tbl_int[index1] = tbl_int[index2];
        tbl_int[index2] = tempo;
        tempo_str = tbl[index1];
        tbl[index1] = tbl[index2];
        tbl[index2] = tempo_str;
    }
}

void sort_tbl_by_time_file(char **tbl, long int *tbl_int, int z)
{
    int index1 = 0;
    int index2 = 1;

    while (index1 != z) {
        while (index2 != z) {
            swap_elem_file(tbl, tbl_int, index1, index2);
            index2++;
        }
        index2 = 0;
        index1++;
    }
    for (int i = 0; i != z; i++) {
        my_putstr(tbl[i]);
        my_putchar(10);
    }
}

void tab_int_time_file(char **tbl, int z, char *filepath)
{
    long int *tbl_int = malloc(sizeof(long int) * z);
    int i = 0;
    struct stat s;

    for (; i != z; i++) {
        stat(my_strcat(filepath, tbl[i]), &s);
        tbl_int[i] = s.st_mtime;
    }
    sort_tbl_by_time_file(tbl, tbl_int, z);
}

void sort_time_with_arg_file_scnd(char *filepath, int z)
{
    char **tab;
    struct dirent *lecture;
    DIR *rep;

    rep = opendir(filepath);
    tab = malloc(sizeof(char*) * (z+1));
    for (int j = 0; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            tab[j] = malloc(sizeof(char)*(my_strlen(lecture->d_name)+1));
            tab[j] = my_strcpy(tab[j], lecture->d_name);
            j++;
        }
    }
    closedir(rep);
    tab_int_time_file(tab, z, filepath);
}

void sort_time_with_arg_file(char *filepath)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    char **tab;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (z; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            z++;
    closedir(rep);
    sort_time_with_arg_file_scnd(filepath, z);
}