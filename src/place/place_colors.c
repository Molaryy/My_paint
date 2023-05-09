/*
** EPITECH PROJECT, 2023
** place_colors
** File description:
** place_colors
*/

#include "src.h"

static void add_personalize_color(sfData_t *data)
{
    sfVector2f pos = {1330, 60};
    sfVector2f size = {1, 1};
    sfIntRect rect = {1375, 30, 50, 50};
    data[74] = (sfData_t){pos, NULL, NULL,
    size, NULL, 0, "util/assets.png", sfWhite};
    data[74].obj = malloc(sizeof(sfSprite *) * 3);
    data[74].obj[0] = ssl_new_sprite(data[74]);
    data[74].size = (sfVector2f){40, 40};
    data[74].pos = (sfVector2f){pos.x + 7, pos.y + 7};
    data[74].obj[1] = ssl_new_rect(data[74]);
    sfRectangleShape_setFillColor(data[74].obj[1], sfTransparent);
    sfRectangleShape_setOutlineThickness(data[74].obj[1], 2);
    sfRectangleShape_setOutlineColor(data[74].obj[1], sfBlack);
    data[74].obj[2] = sfRectangleShape_copy(data[74].obj[1]);
    sfRectangleShape_setOutlineThickness(data[74].obj[2], 4);
    sfSprite_setTextureRect(data[74].obj[0], rect);
}

static void other_color(sfData_t *data, color_t *clr)
{
    sfVector2f pos = {955, 60};
    sfVector2f size = {15, 30};
    int index = 0;
    sfColor color[] = {sfBlack, sfWhite};
    for (int line = 72; line != 74; line++, pos.y += 40, index++){
        data[line] = (sfData_t){pos, NULL, NULL, size, NULL, 0, NULL,
        color[index]};
        data[line].obj = malloc(sizeof(sfCircleShape *) * 3);
        data[line].obj[0] = ssl_new_cirle(data[line]);
        sfCircleShape_setOutlineColor(data[line].obj[0], clr->lt_grey);
        sfCircleShape_setOutlineThickness(data[line].obj[0], 2);
        data[line].obj[1] = sfCircleShape_copy(data[line].obj[0]);
        sfCircleShape_setOutlineColor(data[line].obj[1], sfBlack);
        data[line].obj[2] = sfCircleShape_copy(data[line].obj[1]);
        sfCircleShape_setOutlineThickness(data[line].obj[2], 4);
        sfCircleShape_setOutlineColor(data[line].obj[0], clr->lt_grey);
        sfCircleShape_setOutlineThickness(data[line].obj[0], 2);
    }
    data[72].state = 2;
    add_personalize_color(data);
}

static sfColor *init_colours(color_t *clr)
{
    sfColor *color = malloc(sizeof(sfColor *) * 30);
    sfColor buff[] = {sfBlack, clr->dk_grey1, clr->dk_red, sfRed, clr->orange,
    sfYellow, sfGreen, clr->blue, sfBlue, clr->purple, sfWhite,
    clr->lt_grey, clr->brown, clr->pink, clr->lt_orange, clr->lt_yellow,
    clr->lt_green, sfCyan, clr->lt_blue, clr->lt_red,sfTransparent,
    sfTransparent, sfTransparent, sfTransparent, sfTransparent, sfTransparent,
    sfTransparent, sfTransparent, sfTransparent, sfTransparent};
    for (int i = 0; i != 30; i++)
        color[i] = buff[i];
    return color;
}

void place_color(sfData_t *data, color_t *clr, colorPanel_t *cpn)
{
    sfVector2f pos = {1020, 50};
    sfVector2f size = {10, 30};
    sfColor *color = init_colours(clr);

    for (int index = 0, line = 42; line != 72; pos.y += 30,  pos.x = 1020){
        for (int i = 0; i != 10 && line != 72; i++,
        index++, pos.x += 30, line++){
            data[line] = (sfData_t){pos, NULL, NULL, size, NULL,
            0, NULL, color[index]};
            data[line].obj = malloc(sizeof(sfCircleShape *) * 3);
            data[line].obj[0] = ssl_new_cirle(data[line]);
            sfCircleShape_setOutlineColor(data[line].obj[0], clr->lt_grey);
            sfCircleShape_setOutlineThickness(data[line].obj[0], 2);
            data[line].obj[1] = sfCircleShape_copy(data[line].obj[0]);
            sfCircleShape_setOutlineColor(data[line].obj[1], sfBlack);
            data[line].obj[2] = sfCircleShape_copy(data[line].obj[1]);
            sfCircleShape_setOutlineThickness(data[line].obj[2], 4);
        }
    }
    other_color(data, clr);
}
