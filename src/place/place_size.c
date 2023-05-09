/*
** EPITECH PROJECT, 2023
** place_size
** File description:
** place_size
*/

#include "src.h"

void place_size(sfData_t *data)
{
    sfVector2f pos = {547, 50};
    sfVector2f size = {1, 1};
    sfIntRect rect = {490, 20, 50 ,80};

    data[34] = (sfData_t){pos, NULL, NULL, size, NULL,
    0, "util/assets.png", sfRed};
    data[34].obj = malloc(sizeof(sfSprite *) * (3));
    data[34].obj[0] = ssl_new_sprite(data[34]);
    sfSprite_setTextureRect(data[34].obj[0], rect);
    pos = (sfVector2f){836, 60};
    size = (sfVector2f){1, 1};
    rect = (sfIntRect){915, 25, 50 ,80};
    data[35] = (sfData_t){pos, NULL, NULL, size, NULL,
    0, "util/assets.png", sfRed};
    data[35].obj = malloc(sizeof(sfSprite *) * (3));
    data[35].obj[0] = ssl_new_sprite(data[35]);
    sfSprite_setTextureRect(data[35].obj[0], rect);
}
