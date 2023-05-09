/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

static void destroy_toolbar(toolbar_t *tb)
{
    free(tb->brush);
    free(tb->cp_b);
    free(tb->cpn);
    free(tb->img);
    free(tb->shp);
    free(tb->size);
    free(tb->tools);
    free(tb);
}

static void destroy_bottombar(bottombar_t *bt)
{
    free(bt);
}

static void destroy_page(page_t *pg)
{
    free(pg);
}

static void destroy_button(button_t *bt)
{
    free(bt);
}

void destroy_structures(paint_t *pt)
{
    sfSprite_destroy(pt->pg->page);
    sfRectangleShape_destroy(pt->bpt->rect[0]);
    sfText_destroy(pt->bpt->text[0]);
    sfTexture_destroy(pt->pg->texture);
    sfCircleShape_destroy(pt->data[43].obj[0]);
    sfRenderWindow_destroy(pt->wd);

    destroy_toolbar(pt->tb);
    destroy_page(pt->pg);
    destroy_bottombar(pt->btm_b);
    destroy_button(pt->bt);
    free(pt->clr);
    free(pt->data);
    free(pt);
}
