/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"
#include <stdio.h>

int main(int ac, const char **av)
{
    paint_t *pt = malloc(sizeof(paint_t));

    if (pt == NULL)
        return 84;
    if (init_structures(pt) == 84)
        return 84;
    init_values(pt);
    create_buttons(pt->bpt, pt->clr);
    init_paint(pt);
    destroy_structures(pt);
    return 0;
}
