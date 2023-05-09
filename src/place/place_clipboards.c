/*
** EPITECH PROJECT, 2023
** place_clipboard
** File description:
** place_clipboard
*/

#include "src.h"

void place_clipboard(sfData_t *data)
{
    sfVector2f pos[] = {{20, 70}, {70, 50}, {56, 90}};
    sfVector2f size[] = {{0.1, 0.1}, {0.07, 0.07}, {0.05, 0.05}};
    char *str[] = {"util/clipboard.png", "util/cut.png", "util/sheet.png"};
    int index = 0;

    for (int i = 39; i != 42; i++, index++){
        data[i] = (sfData_t){pos[index], NULL, NULL, size[index], NULL,
        0, str[index], sfRed};
        data[i].obj = malloc(sizeof(sfSprite *) * (3));
        data[i].obj[0] = ssl_new_sprite(data[i]);
    }
}
