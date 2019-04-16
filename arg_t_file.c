/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

char **sort_tbl_by_time_two(char **tbl_sort, long int *tbl_int, int z)
{
    int index1 = 0;
    int index2 = 1;

    while (index1 != z) {
        while (index2 != z) {
            swap_elem(tbl_sort, tbl_int, index1, index2);
            index2++;
        }
        index2 = 0;
        index1++;
    }
    return (tbl_sort);
}

char **tab_int_time_two(char **tbl_sort, int z)
{
    long int tbl_int[z];
    int i = 0;
    struct stat s;

    for (i; i != z; i++) {
        stat(tbl_sort[i], &s);
        tbl_int[i] = s.st_mtime;
    }
    tbl_sort = sort_tbl_by_time_two(tbl_sort, tbl_int, z);
}

char **sort_file_time(char **tbl_sort, char *str)
{
    static int z = 0;

    tbl_sort[z] = malloc(sizeof(char) * (my_strlen(str) + 1));
    tbl_sort[z] = str;
    z++;
    return (tbl_sort);
}

int sort_time_with_one_file_two(char *filepath, int z)
{
    struct dirent *lecture;
    DIR *rep;

    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    for (z; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            z++;
    closedir(rep);
    return (z);
}

void sort_time_with_one_file(char *filepath)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    char **tab;

    z = sort_time_with_one_file_two(filepath, z);
    rep = opendir(filepath);
    if (rep == NULL)
        exit(84);
    tab = malloc(sizeof(char*) * (z+1));
    for (int j = 0; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            tab[j] = malloc(sizeof(char)*(my_strlen(lecture->d_name)+1));
            tab[j] = my_strcat(tab[j], lecture->d_name);
            j++;
        }
    }
    closedir(rep);
    tab_int_time_file(tab, z, filepath);
    exit(0);
}