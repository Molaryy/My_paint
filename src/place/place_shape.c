/*
** EPITECH PROJECT, 2023
** place_shape
** File description:
** place_shape
*/

#include "src.h"

void place_shape(sfData_t *data)
{
    sfVector2f pos[] = {{640, 70}, {690, 70}, {745, 70}};
    sfVector2f size = {0.7, 0.7};
    sfIntRect rect[] = {{0, 0, 70, 70}, {60, 0, 70, 70}, {130, 0, 70, 70}};
    int index = 0;

    for (int i = 36; i != 39; i++, index++){
        data[i] = (sfData_t){pos[index], NULL, NULL,
        size, NULL, 0, "util/shape.png", sfBlack};
        data[i].obj = malloc(sizeof(sfSprite *) * (3));
        data[i].obj[0] = ssl_new_sprite(data[i]);
        sfSprite_setTextureRect(data[i].obj[0], rect[index]);
    }
}
