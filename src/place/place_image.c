/*
** EPITECH PROJECT, 2023
** place_image
** File description:
** place_image
*/

#include "src.h"

void place_image(sfData_t *data)
{
    sfVector2f pos[] = {{130, 70}, {190, 60}, {240, 60},
    {190, 100}, {240, 100}};
    sfVector2f size = {1, 1};
    sfIntRect rect[] = {{120, 20, 50 ,80}, {185, 15, 30, 30},
    {230, 15, 50 , 30}, {185, 65, 30, 30}, {230, 65, 50, 30}};
    int index = 0;

    for (int i = 29; i != 34; i++, index++){
        data[i] = (sfData_t){pos[index], NULL, NULL, size,
        NULL, 0, "util/assets.png", sfRed};
        data[i].obj = malloc(sizeof(sfSprite *) * (3));
        data[i].obj[0] = ssl_new_sprite(data[i]);
        sfSprite_setTextureRect(data[i].obj[0], rect[index]);
    }
}
