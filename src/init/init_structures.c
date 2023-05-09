/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

static int malloc_page(page_t *pg)
{
    if (pg == NULL)
        return 84;
    return 0;
}

static int malloc_button(button_t *bt)
{
    if (bt == NULL)
        return 84;
    return 0;
}

static int malloc_toolbar(toolbar_t *tb)
{
    tb->brush = malloc(sizeof(brushes_t));
    tb->cp_b = malloc(sizeof(clipboard_t));
    tb->cpn = malloc(sizeof(colorPanel_t));
    tb->img = malloc(sizeof(image_t));
    tb->shp = malloc(sizeof(shapes_t));
    tb->size = malloc(sizeof(brushSize_t));
    tb->tools = malloc(sizeof(tools_t));

    if (tb == NULL || tb->brush == NULL || tb->cp_b == NULL
    || tb->cpn == NULL || tb->img == NULL || tb->shp == NULL
    || tb->size == NULL || tb->tools == NULL)
        return 84;
    return 0;
}

static int malloc_bottombar(bottombar_t *btm_b)
{
    if (btm_b == NULL)
        return 84;
    return 0;
}

int init_structures(paint_t *pt)
{
    pt->data = malloc(sizeof(sfData_t) * 75);
    pt->clr = malloc(sizeof(color_t));
    pt->tb = malloc(sizeof(toolbar_t));
    pt->pg = malloc(sizeof(page_t));
    pt->bt = malloc(sizeof(button_t));
    pt->btm_b = malloc(sizeof(page_t));
    pt->mn_scn = malloc(sizeof(mainScene_t));
    pt->bpt = malloc(sizeof(button_paint_t));
    pt->op_sn = malloc(sizeof(openScene_t));

    if (pt->clr == NULL || pt->data == NULL || pt->tb == NULL
    || pt->pg == NULL || pt->bt == NULL || pt->btm_b == NULL
    || malloc_page(pt->pg) == 84 || malloc_button(pt->bt) == 84
    || malloc_toolbar(pt->tb) == 84 || malloc_bottombar(pt->btm_b) == 84
    || pt->mn_scn == NULL || pt->bpt == NULL || pt->op_sn == NULL)
        return 84;
    return 0;
}
