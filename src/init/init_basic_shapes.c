/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

sfText *init_text(sfVector2f pos, sfVector2f size, char *str)
{
    sfFont *font = sfFont_createFromFile("util/font.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setScale(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, str);
    return text;
}

sfRectangleShape *init_rect(sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}
