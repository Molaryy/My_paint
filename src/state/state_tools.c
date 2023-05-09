/*
** EPITECH PROJECT, 2023
** state_tools
** File description:
** state_tools
*/

#include "src.h"

static void verif_cond(int i, sfData_t *data, paint_t *pt, sfEvent event)
{
    data[i].state = 1;
    if (event.type == sfEvtMouseButtonReleased){
        data[i].state = 2;
        pt->tb->tools->old_tool = data[i].obj;
    }
}

static void check_state_color(sfData_t *data, paint_t *pt)
{
    for (int i = 42; i != 72; i++){
        if (data[i].state == 2){
            data[i].state = 0;
            pt->tb->tools->old_i = i;
        }
    }
    if (data[23].obj == pt->tb->tools->old_tool){
        pt->pg->color = pt->tb->tools->earase_color;
        pt->pg->size = 10;
    }
}

static void change_tool(sfData_t *data, paint_t *pt)
{
    if (data[23].obj != pt->tb->tools->old_tool && data[26].obj !=
    pt->tb->tools->old_tool)
        pt->pg->draw = 0;
    else
        pt->pg->draw = 1;
    if (data[23].obj == pt->tb->tools->old_tool || data[24].obj
    == pt->tb->tools->old_tool || data[25].obj == pt->tb->tools->old_tool){
        check_state_color(data, pt);
    } else {
        data[pt->tb->tools->old_i].state = 2;
        pt->pg->color = pt->tb->tools->pen_color;
        pt->pg->size = 2;
    }
}

void state_tools(paint_t *pt, sfData_t *data, sfVector2i mouse, sfEvent event)
{
    sfVector2f rect_pos;

    change_tool(data, pt);
    if (!(mouse.x > 322 && mouse.y > 48 && mouse.x < 506 && mouse.y < 156))
        return;
    for (int i = 23; i != 29; i++){
        rect_pos = sfSprite_getPosition(data[i].obj[0]);
        if (data[i].obj == pt->tb->tools->old_tool)
            continue;
        if (mouse.x >= rect_pos.x && mouse.x <= (rect_pos.x + 30)
        && mouse.y >= rect_pos.y && mouse.y <= (rect_pos.y + 30))
            verif_cond(i, data, pt, event);
        else
            data[i].state = 0;
    }
}
