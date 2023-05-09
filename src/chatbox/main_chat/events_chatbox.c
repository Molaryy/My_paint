/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"

static void set_color_button(sfRectangleShape **rect, sfColor color,
sfVector2i mouse)
{
    for (int i = 1; i < 14; i++) {
        if (mouse_over(rect[i], mouse) == true)
            sfRectangleShape_setFillColor(rect[i], color);
        else
            sfRectangleShape_setFillColor(rect[i], sfWhite);
    }
}

static void states_button(paint_t *pt, int state)
{
    if (mouse_over(pt->mn_scn->rect[2], pt->mouse_main))
            pt->mn_scn->is_back_file = true;
    if (pt->scene != 0)
        return;
    if (state == 1)
        set_color_button(pt->mn_scn->rect, pt->clr->lt_orange, pt->mouse_main);
    else if (state == 2)
        set_color_button(pt->mn_scn->rect, pt->clr->orange, pt->mouse_main);
    if (pt->mn_scn->is_back_file == true)
        pt->mn_scn->is_back_file = mouse_over(pt->mn_scn->back_file,
        pt->mouse_main);
}

static void check_realesed_mouse(paint_t *pt)
{
    if (pt->event_main.type == sfEvtMouseButtonReleased){
        if (mouse_over(pt->mn_scn->rect[10], pt->mouse_main) == true) {
            pt->scene = 1;
            handle_settings_page_scale(pt);
            pt->pg->draw = 1;
            handle_settings_page_rgb(pt);
            sfRenderWindow_close(pt->wd_main);
        }
    }
}

static void check_click_mouse(paint_t *pt)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        if (mouse_over(pt->mn_scn->rect[9], pt->mouse_main) == true)
            init_open_box(pt);
        check_if_clicked_box(pt);
        states_button(pt, 1);
        state_files(pt);
    }
}

void events_chatbox(paint_t *pt)
{
    while (sfRenderWindow_pollEvent(pt->wd_main, &(pt->event_main))) {
        pt->mouse_main = sfMouse_getPositionRenderWindow(pt->wd_main);
        check_click_mouse(pt);
        if (pt->event_main.type == sfEvtClosed){
            pt->scene = 1;
            sfRenderWindow_close(pt->wd_main);
        }
        if (pt->event_main.type == sfEvtMouseMoved)
            states_button(pt, 2);
        input_text(pt);
        show_color_rectangle(pt);
        check_realesed_mouse(pt);
    }
}
