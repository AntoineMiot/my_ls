/*
** EPITECH PROJECT, 2018
** putchar
** File description:
** desc
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
