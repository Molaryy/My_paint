/*
** EPITECH PROJECT, 2023
** event_clipboard
** File description:
** event_clipboard
*/

#include "src.h"

void page_new_scale(paint_t *pt, int width, int height)
{
    pt->pg->pos = (sfVector2f){40 + (width / 2), 219 + (height / 2)};
    pt->pg->width = width;
    pt->pg->height = height;
    pt->pg->texture = sfTexture_create(width, height);
    pt->pg->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    memset(pt->pg->pixels, 255, width * height * 4);
    sfTexture_updateFromPixels(pt->pg->texture, pt->pg->pixels, width,
    height, 0, 0);
    pt->pg->page = sfSprite_create();
    sfSprite_setOrigin(pt->pg->page, (sfVector2f){width / 2, height / 2});
    sfSprite_setTexture(pt->pg->page, pt->pg->texture, sfTrue);
    sfSprite_setPosition(pt->pg->page, pt->pg->pos);
}

void handle_settings_page_scale(paint_t *pt)
{
    sfTexture *text;
    sfTexture *texture = pt->pg->texture;

    if (pt->mn_scn->input[1][0] != '\0' && msl_str_isnum(pt->mn_scn->input[1]))
        pt->pg->width = msl_getnbr(pt->mn_scn->input[1]);
    if (pt->mn_scn->input[2][0] != '\0' && msl_str_isnum(pt->mn_scn->input[2]))
        pt->pg->height = msl_getnbr(pt->mn_scn->input[2]);
    if (pt->pg->width <= 0)
        pt->pg->width = 1;
    if (pt->pg->height <= 0)
        pt->pg->height = 1;
    page_new_scale(pt, pt->pg->width, pt->pg->height);
    pt->data[2].obj[0] = pt->pg->page;
    sfRectangleShape_setSize(pt->data[21].obj[0], (sfVector2f){pt->pg->width,
    pt->pg->height});
    sfSprite_setOrigin(pt->data[21].obj[0],
    (sfVector2f){pt->pg->width / 2, pt->pg->height / 2});
    sfSprite_setPosition(pt->data[21].obj[0], pt->pg->pos);
}

void handle_settings_page_rgb(paint_t *pt)
{
    sfUint8 r = 255, g = 255, b = 255, a = 255;
    if (pt->mn_scn->input[3][0] != '\0' &&
    msl_str_isnum(pt->mn_scn->input[3]) == 1)
        r = my_getnbr(pt->mn_scn->input[3]);
    if (pt->mn_scn->input[4][0] != '\0' &&
    msl_str_isnum(pt->mn_scn->input[4]) == 1)
        g = my_getnbr(pt->mn_scn->input[4]);
    if (pt->mn_scn->input[5][0] != '\0' &&
    msl_str_isnum(pt->mn_scn->input[5]) == 1)
        b = my_getnbr(pt->mn_scn->input[5]);
    if (pt->mn_scn->input[6][0] != '\0' &&
    msl_str_isnum(pt->mn_scn->input[6]) == 1)
        a = my_getnbr(pt->mn_scn->input[6]);
    pt->pg->color = sfColor_fromRGBA(r, g, b, a);
    for (int i = 0; i != pt->pg->height; i++)
        for (int j = 0; j != pt->pg->width; j++)
            expand_pixels(pt->pg, j, i);
    pt->tb->tools->earase_color = sfColor_fromRGBA(r, g, b, a);
    sfTexture_updateFromPixels(pt->pg->texture,
    pt->pg->pixels, pt->pg->width, pt->pg->height, 0, 0);
}

void check_if_clicked_box(paint_t *pt)
{
    if (mouse_over(pt->mn_scn->rect[1], pt->mouse_main) == true)
        pt->mn_scn->wait = 1;
    for (int i = 3; i < 11; i++) {
        if (mouse_over(pt->mn_scn->rect[i], pt->mouse_main) == true){
            pt->mn_scn->wait = i - 1;
        }
    }
}
