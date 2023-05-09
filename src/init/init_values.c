/*
** EPITECH PROJECT, 2023
** init_values.c
** File description:
** init all the values of the paint
*/

#include "src.h"

static void init_toolbar_text(toolbar_t *tb, sfData_t *data, color_t *clr)
{
    sfVector2f size;
    sfVector2f pos;
    char *cord[] = {"Clipboard", "Image", "Tools",
    "Brushes", "Shapes", "Size", "Colours"};
    int cord_pos[] = {20, 190, 395, 545, 685, 845, 1138};
    int index = 0;

    tb->tools->old_sel = 72;
    tb->tools->old_pan = data[72].obj;
    for (int i = 11; i != 18; i++, pos, index++){
        size = (sfVector2f){0.5, 0.5};
        pos = (sfVector2f){cord_pos[index], 140};
        data[i] = (sfData_t){pos, NULL, NULL, size, tb->font,
        0, cord[index], clr->grey};
        data[i].text = ssl_new_text(data[i]);
    }
}

static void init_toolbar_line(toolbar_t *tb, sfData_t *data, color_t *clr)
{
    sfVector2f size = (sfVector2f){1920, 2};
    sfVector2f pos = (sfVector2f){0, 170};
    int index = 0;
    int cord[] = {120, 310, 520, 630, 800, 920};

    data[3] = (sfData_t){pos, NULL, NULL, size, NULL, 0, NULL,
    clr->dk_grey3};
    data[3].obj = malloc(sizeof(sfRectangleShape *));
    data[3].obj[0] = ssl_new_rect(data[3]);
    for (int i = 4; i != 11; i++, pos, index++){
        size = (sfVector2f){1, 115};
        pos = (sfVector2f){cord[index], 50};
        data[i] = (sfData_t){pos, NULL, NULL, size, NULL, 0, NULL,
        clr->lt_grey};
        data[i].obj = malloc(sizeof(sfRectangleShape *));
        data[i].obj[0] = ssl_new_rect(data[i]);
    }
}

static void init_buttons_line(sfData_t *data, color_t *clr)
{
    sfVector2f size;
    sfVector2f pos;
    int cord = 70;

    size = (sfVector2f){1, 25};
    pos = (sfVector2f){cord, 7};
    data[21] = (sfData_t){pos, NULL, NULL, size, NULL, 0, NULL,
    clr->lt_grey};
    data[21].obj = malloc(sizeof(sfRectangleShape *));
    data[21].obj[0] = ssl_new_rect(data[21]);
    size = (sfVector2f){1, 25};
    pos = (sfVector2f){cord + 75, 7};
    data[22] = (sfData_t){pos, NULL, NULL, size, NULL, 0, NULL,
    clr->lt_grey};
    data[22].obj = malloc(sizeof(sfRectangleShape *));
    data[22].obj[0] = ssl_new_rect(data[22]);
}

static void init_buttons_text(button_t *bt, toolbar_t *tb,
sfData_t *data, color_t *clr)
{
    sfVector2f size;
    sfVector2f pos;
    char *cord[] = {"File", "Edit", "Help"};
    int cord_pos = 20;
    int index = 0;

    for (int i = 18; i < 21; i++, pos, index++, cord_pos += 70){
        size = (sfVector2f){0.6, 0.6};
        pos = (sfVector2f){cord_pos, 8};
        data[i] = (sfData_t){pos, NULL, NULL, size, tb->font,
        0, cord[index], clr->grey};
        data[i].text = ssl_new_text(data[i]);
    }
}

void init_values(paint_t *pt)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    pt->wd = sfRenderWindow_create(mode, "MY_PAINT", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(pt->wd, 144);
    pt->tb->font = sfFont_createFromFile("util/font.ttf");
    init_colors(pt->clr);
    init_objects(pt->data, pt->pg, pt->clr);
    init_toolbar_line(pt->tb, pt->data, pt->clr);
    init_toolbar_text(pt->tb, pt->data, pt->clr);
    init_buttons_text(pt->bt, pt->tb, pt->data, pt->clr);
    init_buttons_line(pt->data, pt->clr);
    init_bar_page(pt->clr, pt->data, pt->pg);
    place_tools(pt->data, pt->tb);
    place_image(pt->data);
    place_size(pt->data);
    place_shape(pt->data), place_clipboard(pt->data);
    place_color(pt->data, pt->clr, pt->tb->cpn);
    init_main_scene(pt->mn_scn, pt->clr);
    init_bottombar(pt->btm_b);
    pt->scene = 0, pt->tb->tools->pen_color = sfBlack,
    pt->tb->tools->old_i = 42, pt->tb->cpn->old_color = pt->data[42].obj;
}
