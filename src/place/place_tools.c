/*
** EPITECH PROJECT, 2023
** place_tools
** File description:
** place_tools
*/

#include "src.h"

static void set_state_tool(int i, int index, sfIntRect *rect, sfData_t *data)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 100);
    sfRectangleShape_setOutlineThickness(data[i].obj[1], 1);
    sfRectangleShape_setOutlineColor(data[i].obj[1], sfBlack);
    if (i != 23 && i != 26)
        sfRectangleShape_setPosition(data[i].obj[1],
        (sfVector2f){data[i].pos.x + 5, data[i].pos.y});
    data[i].obj[2] = sfRectangleShape_copy(data[i].obj[1]);
    sfRectangleShape_setOutlineThickness(data[i].obj[2], 2);
    sfRectangleShape_setFillColor(data[i].obj[2], color);
    sfSprite_setTextureRect(data[i].obj[0], rect[index]);
}

void place_tools(sfData_t *data, toolbar_t *tb)
{
    sfVector2f pos[] = {{335, 100}, {400, 100}, {465, 100},
    {335, 50}, {400, 50}, {465, 50}};
    sfVector2f size = {1, 1};
    sfIntRect rect[] = {{325, 65, 30, 30},
    {370, 65, 30, 30}, {420, 65, 30, 30},
    {325, 15, 30, 30}, {370, 15, 30, 30}, {420, 15, 30, 30}};
    int index = 0;

    for (int i = 23; i != 29; i++, index++){
        data[i] = (sfData_t){pos[index], NULL, NULL,
        size, NULL, 0, "util/assets.png", sfBlack};
        data[i].obj = malloc(sizeof(sfSprite *) * (3));
        data[i].obj[0] = ssl_new_sprite(data[i]);
        data[i].size = (sfVector2f){30, 30};
        data[i].color = sfTransparent;
        data[i].obj[1] = ssl_new_rect(data[i]);
        set_state_tool(i, index, rect, data);
    }
    tb->tools->old_tool = data[26].obj;
    data[26].state = 2;
}
