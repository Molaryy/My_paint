/*
** EPITECH PROJECT, 2023
** event_clipboard
** File description:
** event_clipboard
*/

#include "src.h"

void move_cursor(paint_t *pt, int x, int y, sfSprite *sprite)
{
    int setX = pt->mouse.x - x;
    int setY = pt->mouse.y - y;
    sfVector2f pos = {setX, setY};

    sfSprite_setPosition(sprite, pos);
}

static void zoom_framebuffer(paint_t *pt)
{
    sfVector2f scale = sfSprite_getScale(pt->pg->page);
    if (pt->event.type == sfEvtMouseWheelScrolled){
        if (pt->event.mouseWheelScroll.delta == 1) {
            scale.x += 0.05;
            scale.y += 0.05;
            sl(pt->pg->page, scale);
            so(pt->pg->page, vect{540 / scale.x, 360 / scale.y});
            rs(pt->data[21].obj[0], scale);
            ro(pt->data[21].obj[0], vect{540 / scale.x, 360 / scale.y});
        } else if (pt->event.mouseWheelScroll.delta == -1 &&
        scale.x >= 0.1 && scale.y >= 0.1)  {
            scale.x -= 0.05;
            scale.y -= 0.05;
            sl(pt->pg->page, scale);
            so(pt->pg->page, vect{540 / scale.x, 360 / scale.y});
            so(pt->data[21].obj[0], vect{540 / scale.x, 360 / scale.y});
            rs(pt->data[21].obj[0], scale);
            ro(pt->data[21].obj[0], vect{540 / scale.x, 360 / scale.y});
        }
    }
}

static int check_toolbar(paint_t *pt)
{
    if (mouse_over(pt->bpt->rect[3], pt->mouse))
        pt->bpt->is_file_back = true;
    if (mouse_over(pt->bpt->rect[8], pt->mouse))
        pt->bpt->is_edit_back = true;
    if (mouse_over(pt->bpt->rect[12], pt->mouse))
        pt->bpt->is_help_back = true;
    if (pt->bpt->is_file_back == true)
        pt->bpt->is_file_back = mouse_over(pt->bpt->rect[0], pt->mouse);
    if (pt->bpt->is_edit_back == true)
        pt->bpt->is_edit_back = mouse_over(pt->bpt->rect[1], pt->mouse);
    if (pt->bpt->is_help_back == true)
        pt->bpt->is_help_back = mouse_over(pt->bpt->rect[2], pt->mouse);
}

static void check_events(paint_t *pt)
{
    if (pt->event.type == sfEvtClosed
    || (sfMouse_isButtonPressed(sfMouseLeft) &&
    mouse_over(pt->bpt->rect[7], pt->mouse) == true &&
    pt->bpt->is_file_back == true))
        sfRenderWindow_close(pt->wd);
    switch (pt->event.type){
        case (sfEvtMouseMoved): draw_pos_mouse(pt->btm_b, pt->mouse);
        check_toolbar(pt);
            break;
    }
}

void paint_events(paint_t *pt)
{
    sfVector2u size; float x, y;

    
    while (sfRenderWindow_pollEvent(pt->wd, &(pt->event))) {
        pt->mouse = sfMouse_getPositionRenderWindow(pt->wd);
        size = sfRenderWindow_getSize(pt->wd);
        x = size.x;
        y = size.y;
        pt->mouse.x /= x / 1920;
        pt->mouse.y /= y / 1080;
        if (sfMouse_isButtonPressed(sfMouseLeft)
        && mouse_over(pt->bpt->rect[6], pt->mouse) == true
        && pt->bpt->is_file_back == true)
            create_file(pt);
        if (sfMouse_isButtonPressed(sfMouseLeft)
        && mouse_over(pt->bpt->rect[4], pt->mouse) == true
        && pt->bpt->is_file_back == true)
            pt->scene = 0;
        draw_framebuffer_line(pt->pg, pt);
        check_events(pt);
        zoom_framebuffer(pt);
    }
}
