/*
** EPITECH PROJECT, 2023
** state_panel
** File description:
** state_panel
*/

#include "src.h"

bool color_cmp(sfColor color1, sfColor color2)
{
    if (color1.a == color2.a && color1.b == color2.b
    && color1.g == color2.g && color1.r == color2.r)
        return true;
    return false;
}

static void get_right_color(sfData_t *data, toolbar_t *tb, page_t *pg)
{
    sfColor color;
    sfColor bis = sfCircleShape_getFillColor(data[tb->tools->old_sel].obj[0]);

    for (int i = 42; i != 72; i++){
        color = sfCircleShape_getFillColor(data[i].obj[0]);
        if (color_cmp(color, bis)){
            data[i].state = 2;
            tb->tools->old_i = i;
            tb->cpn->old_color = data[i].obj;
            pg->color = color;
        }
        if (i != tb->tools->old_i && data[i].state == 2)
            data[i].state = 0;
    }
}

static int get_panel(paint_t *pt, int i, int d)
{
    if (d <= pt->data[i].size.x){
        pt->data[i].state = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)){
            pt->data[i].state = 2;
            pt->tb->tools->old_sel = i;
            pt->tb->tools->pen_color = pt->pg->color;
            pt->data[pt->tb->tools->old_sel].state = 0;
            pt->tb->tools->old_pan = pt->data[i].obj;
            get_right_color(pt->data, pt->tb, pt->pg);
            return 1;
        }
    }
}

void change_panel(paint_t *pt)
{
    sfVector2i mouse = pt->mouse;
    sfData_t *data = pt->data;
    int dx = 0, dy = 0, d1 = 0, d2 = 0, d3 = 0, d = 0;

    for (int i = 72; i != 74; i++){
        dx = mouse.x - data[i].pos.x - 4;
        dy = mouse.y - data[i].pos.y - 10;
        d1 = dx * dx;
        d2 = dy * dy;
        d3 = d1 + d2;
        d = sqrt(d3);
        if (i == pt->tb->tools->old_sel)
            continue;
        pt->data[i].state = 0;
        if (get_panel(pt, i, d) == 1)
            return;
        }
}
