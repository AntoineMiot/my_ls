/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void tab_int_time(char **tbl, int z)
{
    long int tbl_int[z];
    int i = 0;
    struct stat s;

    for (i; i != z; i++) {
        stat(tbl[i], &s);
        tbl_int[i] = s.st_mtime;
    }
    sort_tbl_by_time(tbl, tbl_int, z);
}

void sort_time_no_arg(void)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    char **tab;

    rep = opendir(".");
    for (z; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            z++;
    closedir(rep);
    rep = opendir(".");
    tab = malloc(sizeof(char*) * (z+1));
    for (int j = 0; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            tab[j] = malloc(sizeof(char)*(my_strlen(lecture->d_name)+1));
            tab[j] = lecture->d_name;
            j++;
        }
    }
    closedir(rep);
    tab_int_time(tab, z);
}

void just_file_putchar_tt(int ac, int i)
{
    if (i + 1 != ac)
        my_putchar('\n');
}

void arg_tt_two(int ac, char **av, int z, int i)
{
    int j = 0;
    char **tbl_sort;

    tbl_sort = malloc(sizeof(char*) * i);
    for (z; z != ac; z++) {
        tbl_sort = sort_file_time(tbl_sort, av[z]);
        j++;
    }
    tbl_sort = tab_int_time_two(tbl_sort, j);
    z = 0;
    for (z; z != j; z++) {
        my_putstr(tbl_sort[z]);
        my_putstr(":\n");
        sort_time_with_arg_file(tbl_sort[z]);
        just_file_putchar_tt(j, z);
    }
}

void arg_tt(int ac, char **av)
{
    int i = 1;
    int z;
    int nb = -1;
    char **tbl_sort;

    for (i; i != ac; i++)
        if (av[i][0] != '-')
            break;
    for (int m = 0; m != ac; m++)
        if (av[m][0] != '-')
            nb = nb + 1;
    if (nb == 1)
        sort_time_with_one_file(my_strcat("./", av[i]));
    z = i;
    if (nb == 0)
        sort_time_no_arg();
    if (nb > 1)
        arg_tt_two(ac, av, z, i);
}