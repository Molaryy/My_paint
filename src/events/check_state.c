/*
** EPITECH PROJECT, 2023
** check_state
** File description:
** check_state
*/

#include "src.h"

static void state_color_changer(paint_t *pt)
{
    sfVector2i mouse = pt->mouse;
    int i = 74;
    sfVector2f pos = {1330, 65};

    if (pt->data[i].obj == pt->tb->tools->old_tool)
        return;
    if (!(mouse.x > 1329 && mouse.y > 62
    && mouse.x < 1373 && mouse.y < 107))
        return;
    if (mouse.x > 1330 && mouse.y > 65 && mouse.x <= 1330 + 30
    && mouse.y <= 65 + 30){
        pt->data[i].state = 1;
        if (sfEvtMouseButtonReleased == pt->event.type){
            pt->data[i].state = 2;
            pt->tb->tools->old_tool = pt->data[i].obj;
        }
    } else
    pt->data[i].state = 0;
}

static void check_pos(sfData_t *data, int i, toolbar_t *tb, paint_t *pt)
{
    data[i].state = 1;
    if (sfEvtMouseButtonReleased == pt->event.type){
        pt->pg->color = sfCircleShape_getFillColor(data[i].obj[0]);
        tb->tools->pen_color = pt->pg->color;
        tb->tools->old_i = i;
        data[i].state = 2;
        data[26].state = 2;
        data[24].state = 0;
        data[25].state = 0;
        data[23].state = 0;
        for (int i = 0; i != 3; i++)
            sfCircleShape_setFillColor(data[tb->tools->old_sel].obj[i],
            pt->pg->color);
        tb->tools->old_tool = data[26].obj;
        tb->cpn->old_color = data[i].obj;
    }
}

static void state_color(sfVector2i mouse, paint_t *pt)
{
    sfVector2f size;
    int center = 0;
    int dx = 0, dy = 0, d1 = 0, d2 = 0, d3 = 0, d = 0;
    if (!(mouse.x > 915 && mouse.y > 40 && mouse.x < 1390 && mouse.y < 173))
        return;
    change_panel(pt);
    for (int i = 42; i != 72; i++){
        dx = mouse.x - pt->data[i].pos.x - 4;
        dy = mouse.y - pt->data[i].pos.y - 10;
        d1 = dx * dx;
        d2 = dy * dy;
        d3 = d1 + d2;
        d = sqrt(d3);
        if (pt->data[i].obj == pt->tb->cpn->old_color)
            continue;
        if (d <= pt->data[i].size.x){
            check_pos(pt->data, i, pt->tb, pt);
        } else
            pt->data[i].state = 0;
    }
}

void check_state(paint_t *pt)
{
    state_tools(pt, pt->data, pt->mouse, pt->event);
    state_color_changer(pt);
    state_color(pt->mouse, pt);
}
