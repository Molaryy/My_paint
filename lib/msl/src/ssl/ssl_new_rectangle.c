/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"
#include "../../../includes/src_struct.h"

sfRectangleShape *ssl_new_rect(sfData_t data)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, data.size);
    sfRectangleShape_setFillColor(rect, data.color);
    sfRectangleShape_setPosition(rect, data.pos);
    return rect;
}
