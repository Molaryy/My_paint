/*
** EPITECH PROJECT, 2023
** init_bar_page
** File description:
** init_bar_page
*/

#include "src.h"

void init_bar_page(color_t *clr, sfData_t *data, page_t *pg)
{
    data[21].obj = malloc(sizeof(sfRectangleShape *));
    data[21].obj[0] = sfRectangleShape_create();
    sfVector2f scale_page = {pg->width, pg->height};
    sfVector2f pos_page = sfSprite_getPosition(data[2].obj[0]);
    pos_page.x -= pg->width / 2;
    pos_page.y -= pg->height / 2;
    sfRectangleShape_setOutlineThickness(data[21].obj[0], 5);
    sfRectangleShape_setOutlineColor(data[21].obj[0], clr->dk_grey3);
    sfRectangleShape_setSize(data[21].obj[0], scale_page);
    sfRectangleShape_setFillColor(data[21].obj[0], sfTransparent);
    sfRectangleShape_setPosition(data[21].obj[0], pos_page);
}
