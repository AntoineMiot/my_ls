/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void swap_elem(char **tbl, long int *tbl_int, int index1, int index2)
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

void sort_tbl_by_time(char **tbl, long int *tbl_int, int z)
{
    int index1 = 0;
    int index2 = 1;

    while (index1 != z) {
        while (index2 != z) {
            swap_elem(tbl, tbl_int, index1, index2);
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