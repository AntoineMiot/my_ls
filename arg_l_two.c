/*
** EPITECH PROJECT, 2018
** sort_str.c
** File description:
** Trier des mots
*/
#include "include/my.h"

void time_modif(char *str)
{
    struct stat s;

    stat(str, &s);
    for (int i = 4; i != 16; i++)
        my_putchar(ctime(&s.st_mtime)[i]);
    my_putchar(9);
}

void nlink(char *str)
{
    struct stat s;
    struct passwd *pwd;
    struct group *g;

    stat(str, &s);
    pwd = getpwuid(s.st_uid);
    g = getgrgid(s.st_gid);
    my_putchar(9);
    my_put_nbr(s.st_nlink);
    my_putchar(9);
    my_putstr(pwd->pw_name);
    my_putchar(9);
    my_putstr(g->gr_name);
    my_putchar(9);
    my_put_nbr(s.st_size);
    my_putchar(9);
}

void other(char *str)
{
    struct stat s;

    stat(str, &s);
    if (s.st_mode & S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if (s.st_mode & S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
    if (s.st_mode & S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
}

void group(char *str)
{
    struct stat s;

    stat(str, &s);
    if (s.st_mode & S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if (s.st_mode & S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
    if (s.st_mode & S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
}

void utilisa(char *str)
{
    struct stat s;

    stat(str, &s);
    if (s.st_mode & S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if (s.st_mode & S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    if (s.st_mode & S_IXUSR)
        my_putchar('x');
    else
        my_putchar('-');
}