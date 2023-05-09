/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

static void draw_buttons(paint_t *pt)
{
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawText(pt->wd, pt->btm_b->text[i], NULL);
    draw_toolbar_buttons(pt);
}

static void draw_state(paint_t *pt, int i)
{
    for (int j = -1; j != pt->data[i].state; j++){
        sfRenderWindow_drawShape(pt->wd,
        pt->data[i].obj[j + 1], NULL);
    }
}

static void draw_obj(paint_t *pt)
{
    for (int i = 0; i != 75; i++) {
        if (i == 2 && pt->scene == 0 || i == 21 && pt->scene == 0)
            continue;
        if (pt->scene != 0)
            check_state(pt);
        if (pt->data[i].text != NULL){
            sfRenderWindow_drawText(pt->wd,
            pt->data[i].text, NULL);
        }
        if (pt->data[i].obj != NULL){
            draw_state(pt, i);
        }
    }
    if (pt->scene != 0) {
        for (int i = 0; i < 2; i++)
            sfRenderWindow_drawText(pt->wd, pt->btm_b->text[i], NULL);
    }
    draw_buttons(pt);
}

static void paint_update(paint_t *pt)
{
    sfRenderWindow_clear(pt->wd, pt->clr->dk_grey1);
    draw_obj(pt);
    sfRenderWindow_display(pt->wd);
}

void init_paint(paint_t *pt)
{
    pt->scene = 0;

    while (sfRenderWindow_isOpen(pt->wd)) {
        paint_update(pt);
        paint_events(pt);
        if (pt->scene == 0)
            init_chatbox(pt);
        if (sfMouse_isButtonPressed(sfMouseLeft)
        && mouse_over(pt->bpt->rect[5], pt->mouse) == true)
            init_open_box(pt);
    }
}
