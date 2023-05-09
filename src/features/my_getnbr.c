/*
** EPITECH PROJECT, 2022
** My_getnbr.c
** File description:
** Returns a number from a string
*/

#include "src.h"
#include <stddef.h>

static int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return (0);
}

static int is_neg(char *str)
{
    int n = 1;

    if (str == NULL)
        return -1;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[0] == '-')
            n *= -1;
    }

    return (n);
}

static int get_start_index(char *str)
{
    int i = 0;
    int n = 0;

    if (str == NULL)
        return -1;

    for (; str[i] != '\0'; i++) {
        if (is_digit(str[i]))
            return (n);
        if (is_digit(str[i]) == 0)
            n++;
    }
    return (n);
}

int is_overflow(char *str)
{
    if ((msl_strlen(str) > 10 && str[0] != '-') ||
        (msl_strlen(str) > 11 && str[0] == '-'))
        return 84;
    return 0;
}

int my_getnbr(char *str)
{
    int	nb = 0;
    int	i = get_start_index(str);
    int	neg = is_neg(str);

    if ((str == NULL && i == -1 && neg == -1) || (is_overflow(str) == 84))
        return 84;

    for (; str[i] != '\0' && is_digit(str[i]); i++) {
        nb *= 10;
        nb += str[i] - 48;
    }

    return (nb * neg);
}
