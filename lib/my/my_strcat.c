/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcat(char *str_first, char const *str_scnd)
{
    int k = 0;
    char *strrtn = malloc(sizeof(char)*
    (my_strlen(str_first) + my_strlen(str_scnd) + 2));

    for (int i = 0; str_first[i] != '\0'; i++) {
        strrtn[k] = str_first[i];
        k++;
    }
    for (int i = 0; str_scnd[i] != '\0'; i++) {
        strrtn[k] = str_scnd[i];
        k++;
    }
    strrtn[k] = '\0';
    return (strrtn);
}