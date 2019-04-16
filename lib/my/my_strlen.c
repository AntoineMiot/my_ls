/*
** EPITECH PROJECT, 2018
** swap
** File description:
** swap to integer
*/

int my_strlen(char const *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len = len + 1;
    }
    return (len);
}

