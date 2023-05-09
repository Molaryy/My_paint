/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"
#include "../../../includes/src_struct.h"

sfSprite *ssl_new_sprite(sfData_t data)
{
    sfTexture *texture = sfTexture_createFromFile(data.path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, data.size);
    sfSprite_setPosition(sprite, data.pos);
    return sprite;
}
