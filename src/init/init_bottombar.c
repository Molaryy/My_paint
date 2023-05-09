/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

void init_bottombar(bottombar_t *btm_br)
{
    sfVector2f size = {0.5, 0.5};
    sfVector2f pos_x = {25, 1055};
    sfVector2f pos_y = {100, 1055};
    btm_br->text = malloc(sizeof(sfText *) * 2);

    btm_br->text[0] = init_text(pos_x, size, "x =");
    btm_br->text[1] = init_text(pos_y, size, "y =");
}
