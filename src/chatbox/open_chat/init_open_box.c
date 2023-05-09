/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"

void chat_open(paint_t *pt)
{
    pt->op_sn->rect[0] = init_rect(vect{150, 20},
    vect{230,  35}, pt->clr->dk_grey3);
    pt->op_sn->rect[1] = init_rect(vect{80, 250},
    vect{90, 35}, pt->clr->dk_grey3);
    pt->op_sn->rect[2] = init_rect(vect{220, 250},
    vect{90, 35}, pt->clr->dk_grey3);
    pt->op_sn->text[0] = init_text(vect{40, 20},
    vect{0.7, 0.7}, "File name");
    pt->op_sn->text[1] = init_text(vect{235, 252},
    vect{0.7, 0.7}, "Open");
    pt->op_sn->text[2] = init_text(vect{90, 252},
    vect{0.7, 0.7}, "Cancel");
    pt->op_sn->text[3] = init_text(vect{165, 23},
    vect{0.7, 0.7}, "Example");
    pt->op_sn->text[4] = init_text(vect{40, 60},
    vect{0.7, 0.7}, "File doesn't exist or invalid file");
    sfText_setColor(pt->op_sn->text[4], sfRed);
}

static void open_update(paint_t *pt)
{
    sfRenderWindow_clear(pt->wd_open, pt->clr->dk_grey1);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawRectangleShape(pt->wd_open,
        pt->op_sn->rect[i], NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(pt->wd_open, pt->op_sn->text[i], NULL);
    if (pt->op_sn->file_exits == true)
        sfRenderWindow_drawText(pt->wd_open, pt->op_sn->text[4], NULL);
    sfRenderWindow_display(pt->wd_open);
}

void init_open_box(paint_t *pt)
{
    sfVideoMode mode = {400, 400};

    pt->op_sn->file_exits = false;
    pt->op_sn->rect = malloc(sizeof(sfRectangleShape *) * 3);
    pt->op_sn->input = malloc(sizeof(char) * (20 + 1));
    memset(pt->op_sn->input, '\0', 21);
    pt->op_sn->text = malloc(sizeof(sfText *) * 5);
    pt->wd_open = sfRenderWindow_create(mode, "Open", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(pt->wd_open, 144);
    chat_open(pt);
    sfRenderWindow_setPosition(pt->wd_open, (sfVector2i){560, 410});
    while (sfRenderWindow_isOpen(pt->wd_open)){
        open_events(pt);
        open_update(pt);
    }
}
