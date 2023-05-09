/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"

static void draw_files_rect(paint_t *pt)
{
    if (pt->mn_scn->is_back_file == true){
        sfRenderWindow_drawRectangleShape(pt->wd_main,
        pt->mn_scn->rect[12], NULL);
        sfRenderWindow_drawRectangleShape(pt->wd_main,
        pt->mn_scn->rect[13], NULL);
        sfRenderWindow_drawText(pt->wd_main, pt->mn_scn->text[20], NULL);
        sfRenderWindow_drawText(pt->wd_main, pt->mn_scn->text[21], NULL);
    }
}

void show_color_rectangle(paint_t *pt)
{
    int r = 255;
    int g = 255;
    int b = 255;
    int a = 255;

    if (pt->mn_scn->input[3][0] != '\0')
        r = my_getnbr(pt->mn_scn->input[3]);
    if (pt->mn_scn->input[4][0] != '\0')
        g = my_getnbr(pt->mn_scn->input[4]);
    if (pt->mn_scn->input[5][0] != '\0')
        b = my_getnbr(pt->mn_scn->input[5]);
    if (pt->mn_scn->input[6][0] != '\0')
        a = my_getnbr(pt->mn_scn->input[6]);
    sfRectangleShape_setFillColor(pt->mn_scn->rect[11],
    sfColor_fromRGBA(r, g, b, a));
    if (r < 0 || r > 255 || g < 0 || g > 255
    || b < 0 || b > 255 || a < 0 || a > 255)
        pt->mn_scn->invalid_color = true;
    else
        pt->mn_scn->invalid_color = false;
}

static void draw_main_scene(paint_t *pt)
{
    if (pt->scene != 0)
        return;
    for (int i = 0; i < 12; i++){
        sfRenderWindow_drawRectangleShape(pt->wd_main,
        pt->mn_scn->rect[i], NULL);
    }
    for (int i = 0; i < 20; i++){
        if (i != 18)
            sfRenderWindow_drawText(pt->wd_main, pt->mn_scn->text[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(pt->wd_main,
    pt->mn_scn->back_file, NULL);
    draw_files_rect(pt);
    if (pt->mn_scn->invalid_color == true)
        sfRenderWindow_drawText(pt->wd_main, pt->mn_scn->text[18], NULL);
}

void init_chatbox(paint_t *pt)
{
    sfVideoMode mode = {800, 500, 32};

    pt->wd_main = sfRenderWindow_create(mode, "New", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(pt->wd_main, 144);
    sfRenderWindow_setPosition(pt->wd_main, (sfVector2i){560, 410});
    pt->mn_scn->is_back_file = false;
    if (pt->scene == 0) {
        while (sfRenderWindow_isOpen(pt->wd_main)) {
            events_chatbox(pt);
            sfRenderWindow_clear(pt->wd_main, sfRed);
            draw_main_scene(pt);
            sfRenderWindow_display(pt->wd_main);
        }
    }
}
