/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

void draw_pos_mouse(bottombar_t *btml, sfVector2i mouse)
{
    char *x = "x = ";
    char *y = "y = ";

    if (mouse.x > 0 && mouse.y > 0){
        x = msl_strcat("x = ", transform_int_to_text(mouse.x));
        y = msl_strcat("|   y = ", transform_int_to_text(mouse.y));
    }
    sfText_setString(btml->text[0], x);
    sfText_setString(btml->text[1], y);
}

bool mouse_over(sfRectangleShape *rect, sfVector2i mouse)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    sfVector2f size = sfRectangleShape_getSize(rect);

    if (mouse.x >= rect_pos.x && mouse.x <= (rect_pos.x + size.x)
        && mouse.y >= rect_pos.y && mouse.y <= (rect_pos.y + size.y))
            return true;
    return false;
}
