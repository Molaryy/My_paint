/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"

static void check_file(paint_t *pt)
{
    bool has_ext = false;
    struct stat info;

    if (find_str_in_str(pt->op_sn->input, ".jpg") == true
        || find_str_in_str(pt->op_sn->input, ".bmp") == true
        || find_str_in_str(pt->op_sn->input, ".png") == true)
        pt->op_sn->file_exits = false;
    else {
        pt->op_sn->file_exits = true;
        has_ext = true;
    }
    if (stat(pt->op_sn->input, &info) == -1 || has_ext == true)
        pt->op_sn->file_exits = true;
}

static void file_input(paint_t *pt)
{
    static int i = 0;

    if (i < 20 && pt->event_open.text.unicode != 8) {
        pt->op_sn->input[i] = (char)pt->event_open.text.unicode;
        if (i + 1 < 20)
            pt->op_sn->input[i + 1] = '\0';
        sfText_setString(pt->op_sn->text[3], pt->op_sn->input);
        i++;
    }
    if (pt->event_open.text.unicode == 8) {
        if (i - 1 >= 0)
            i--;
        pt->op_sn->input[i] = '\0';
        sfText_setString(pt->op_sn->text[3], pt->op_sn->input);
    }
    pt->op_sn->input[20] = '\0';
}

static void open_image(paint_t *pt)
{
    sfImage *img = sfImage_createFromFile(pt->op_sn->input);
    sfTexture *txt = sfTexture_createFromImage(img, NULL);
    sfVector2u size = sfTexture_getSize(txt);
    memset(pt->pg->pixels, 255,  pt->pg->width * pt->pg->height * 4);
    pt->pg->texture = txt;
    sfSprite_setTexture(pt->pg->page, pt->pg->texture, sfFalse);
    sfTexture_updateFromPixels(pt->pg->texture, pt->pg->pixels, pt->pg->width,
    pt->pg->height, 0, 0);
}

static int check_open_file(paint_t *pt, int check)
{
    if (pt->op_sn->file_exits == false && check == 0) {
        open_image(pt);
        check++;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    mouse_over(pt->op_sn->rect[2], pt->mouse_open) == true){
        pt->scene = 1;
        sfRenderWindow_close(pt->wd_open);
        sfRenderWindow_close(pt->wd_main);
    }
    return check;
}

void open_events(paint_t *pt)
{
    static bool input = true;
    static int check = 0;

    while (sfRenderWindow_pollEvent(pt->wd_open, &(pt->event_open))){
        pt->mouse_open = sfMouse_getPositionRenderWindow(pt->wd_open);
        if (pt->event_open.type == sfEvtClosed){
            sfRenderWindow_close(pt->wd_open);
        }
        if (pt->event_open.type == sfEvtTextEntered && input == true)
            file_input(pt);
        check_file(pt);
        check = check_open_file(pt, check);
    }
}
