/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"

int get_int(long nb)
{
    int n = 0;

    while (nb > 0) {
        nb = nb / 10;
        n++;
    }
    return n;
}

char *transform_int_to_text(int nb)
{
    int number = 0;
    int num = get_int(nb);
    char *str = malloc(sizeof(char) * (num + 1));
    int i = 0;

    str[num] = '\0';
    if (nb < 0) {
        str[i] = '-';
        nb = nb * -1;
        i++;
    }
    for (; nb > 0; num--) {
        number = nb % 10;
        str[num - 1] = (number + 48);
        nb = nb / 10;
    }
    return str;
}
