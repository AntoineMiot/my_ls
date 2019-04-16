/*
** EPITECH PROJECT, 2018
** swap
** File description:
** swap to integer
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

