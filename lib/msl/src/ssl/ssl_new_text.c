/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"
#include "../../../includes/src_struct.h"

sfText *ssl_new_text(sfData_t data)
{
    sfText *text = sfText_create();

    sfText_setFont(text, data.font);
    sfText_setScale(text, data.size);
    sfText_setPosition(text, data.pos);
    sfText_setColor(text, data.color);
    sfText_setString(text, data.path);
    return text;
}
