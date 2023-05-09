/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

void draw_objects(paint_t *pt, int start, int end, int state)
{
    if (state == 1){
        for (int i = start; i < end; i++)
            sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[i], NULL);
    }
    if (state == 2){
        for (int i = start; i < end; i++)
            sfRenderWindow_drawText(pt->wd, pt->bpt->text[i], NULL);
    }
}

void draw_toolbar_buttons(paint_t *pt)
{
    if (pt->bpt->is_file_back == true){
        sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[0], NULL);
        draw_objects(pt, 4, 8, 1);
        draw_objects(pt, 1, 5, 2);
    } else if (pt->bpt->is_edit_back == true) {
        sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[1], NULL);
        draw_objects(pt, 9, 12, 1);
        draw_objects(pt, 6, 9, 2);
    }
    if (pt->bpt->is_help_back == true) {
        sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[2], NULL);
        sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[13], NULL);
        sfRenderWindow_drawText(pt->wd, pt->bpt->text[10], NULL);
    }
    sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[3], NULL);
    sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[8], NULL);
    sfRenderWindow_drawRectangleShape(pt->wd, pt->bpt->rect[12], NULL);
    sfRenderWindow_drawText(pt->wd, pt->bpt->text[0], NULL);
    sfRenderWindow_drawText(pt->wd, pt->bpt->text[5], NULL);
    sfRenderWindow_drawText(pt->wd, pt->bpt->text[9], NULL);
}

static void init_text_buttons(button_paint_t *bp)
{
    bp->text[0] = init_text(vect{25, 8}, vect{0.6, 0.6}, "File");
    bp->text[1] = init_text(vect{21, 44}, vect{0.6, 0.6}, "New");
    bp->text[2] = init_text(vect{18, 81}, vect{0.6, 0.6}, "Open");
    bp->text[3] = init_text(vect{18, 117}, vect{0.6, 0.6}, "Save");
    bp->text[4] = init_text(vect{23, 153}, vect{0.6, 0.6}, "Exit");
    bp->text[5] = init_text(vect{98, 8}, vect{0.6, 0.6}, "Edit");
    bp->text[6] = init_text(vect{91, 44}, vect{0.6, 0.6}, "Pencil");
    bp->text[7] = init_text(vect{88, 81}, vect{0.6, 0.6}, "Eraser");
    bp->text[8] = init_text(vect{85, 117}, vect{0.6, 0.6}, "Bucket");
    bp->text[9] = init_text(vect{170, 8}, vect{0.6, 0.6}, "Help");
    bp->text[10] = init_text(vect{165, 44}, vect{0.6, 0.6}, "Guide");
}

static void init_buttons_rects(button_paint_t *bp, sfColor clr, sfVector2f size)
{
    bp->rect[0] = init_rect(vect{9, 7}, vect{67, 175}, sfBlack);
    bp->rect[1] = init_rect(vect{84, 7}, vect{67, 140}, sfBlack);
    bp->rect[2] = init_rect(vect{159, 7}, vect{67, 65}, sfBlack);
    bp->rect[3] = init_rect(vect{10, 7}, size, clr);
    bp->rect[4] = init_rect(vect{10, 43}, size, clr);
    bp->rect[5] = init_rect(vect{10, 79}, size, clr);
    bp->rect[6] = init_rect(vect{10, 115}, size, clr);
    bp->rect[7] = init_rect(vect{10, 151}, size, clr);
    bp->rect[8] = init_rect(vect{85, 7}, size, clr);
    bp->rect[9] = init_rect(vect{85, 43}, size, clr);
    bp->rect[10] = init_rect(vect{85, 79}, size, clr);
    bp->rect[11] = init_rect(vect{85, 115}, size, clr);
    bp->rect[12] = init_rect(vect{160, 7}, size, clr);
    bp->rect[13] = init_rect(vect{160, 43}, size, clr);
    for (int i = 0; i < 14; i++) {
        sfRectangleShape_setOutlineThickness(bp->rect[i], 1);
        sfRectangleShape_setOutlineColor(bp->rect[i], sfBlack);
    }
}

void create_buttons(button_paint_t *bp, color_t *clr)
{
    int start_X = 10;
    int start_Y = 3;
    sfVector2f pos = {start_X, start_Y};
    sfVector2f size = {65, 28};
    bp->rect = malloc(sizeof(sfRectangleShape *) * 14);
    bp->text = malloc(sizeof(sfText *) * 11);
    bp->is_file = false;
    bp->is_edit = false;
    bp->is_help = false;
    bp->is_file_back = false;
    bp->is_edit_back = false;
    bp->is_help_back = false;
    init_text_buttons(bp);
    init_buttons_rects(bp, clr->dk_grey1, size);
}
