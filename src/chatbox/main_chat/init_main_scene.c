/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

static int init_input_text(mainScene_t *sc)
{
    sc->wait = 0;
    sc->input = malloc(sizeof(char *) * 7);
    sc->input[0] = malloc(sizeof(char) * (21 + 1));
    sc->input[1] = malloc(sizeof(char) * (4 + 1));
    sc->input[2] = malloc(sizeof(char) * (4 + 1));
    sc->input[3] = malloc(sizeof(char) * (3 + 1));
    sc->input[4] = malloc(sizeof(char) * (3 + 1));
    sc->input[5] = malloc(sizeof(char) * (3 + 1));
    sc->input[6] = malloc(sizeof(char) * (3 + 1));
    memset(sc->input[0], '\0', 22);
    memset(sc->input[1], '\0', 5);
    memset(sc->input[2], '\0', 5);
    memset(sc->input[3], '\0', 4);
    memset(sc->input[4], '\0', 4);
    memset(sc->input[5], '\0', 4);
    memset(sc->input[6], '\0', 4);
}

static int init_values_text(mainScene_t *sc, color_t *clr)
{
    sfVector2f pos = {122, 22}, size = {0.7, 0.7};
    size_t idx = 0;
    char *title[] = {"Example", "1080", "720", "255", "255", "255",
    "255"};

    sc->text[10] = init_text((sfVector2f){175, 22}, size, title[0]);
    sc->text[11] = init_text((sfVector2f){150, 200}, size, title[1]);
    sc->text[12] = init_text((sfVector2f){155, 265}, size, title[2]);
    sc->text[13] = init_text((sfVector2f){715, 120}, size, title[3]);
    sc->text[14] = init_text((sfVector2f){715, 165}, size, title[4]);
    sc->text[15] = init_text((sfVector2f){715, 210}, size, title[5]);
    sc->text[16] = init_text((sfVector2f){715, 255}, size, title[6]);
    sc->text[17] = init_text((sfVector2f){280, 400}, size, "Open");
    sc->text[18] = init_text((sfVector2f){640, 290}, size, "Invalid color:");
    sc->text[19] = init_text((sfVector2f){185, 85}, size, ".jpg");
    sc->text[20] = init_text((sfVector2f){185, 125}, size, ".bmp");
    sc->text[21] = init_text((sfVector2f){185, 165}, size, ".png");
    for (int i = 9; i < 22; i++)
        sfText_setFillColor(sc->text[i], sfBlack);
    sfText_setColor(sc->text[18], sfRed);
}

static void text_main_scene(mainScene_t *sc, color_t *clr)
{
    char *title[] = {"Width:", "Height:", "Color:", "R:", "G:", "B:",
    "A:", "Apply"};
    sfVector2f pos = {40, 22};
    sfVector2f size = {0.7, 0.7};

    sc->text[0] = init_text(pos, size, "File name:");
    sc->text[1] = init_text(vect{40, 85}, size, "File type:");
    sc->text[2] = init_text(vect{40, 200}, size, title[0]);
    sc->text[3] = init_text(vect{40, 265}, size, title[1]);
    sc->text[4] = init_text(vect{465, 65}, size, title[2]);
    sc->text[5] = init_text(vect{660, 120}, size, title[3]);
    sc->text[6] = init_text(vect{660, 165}, size, title[4]);
    sc->text[7] = init_text(vect{660, 210}, size, title[5]);
    sc->text[8] = init_text(vect{660, 255}, size, title[6]);
    sc->text[9] = init_text(vect{430, 400}, size, title[7]);
}

static void init_color_buttons(mainScene_t *sc, color_t *clr, sfVector2f size)
{
    sc->rect[1] = init_rect(vect{170, 20}, vect{200, 30}, sfWhite);
    sc->rect[2] = init_rect(vect{160, 85}, size, sfWhite);
    sc->rect[3] = init_rect(vect{120, 200}, size, sfWhite);
    sc->rect[4] = init_rect(vect{120, 265}, size, sfWhite);
    sc->rect[5] = init_rect(vect{695, 115}, vect{90, 35}, sfWhite);
    sc->rect[6] = init_rect(vect{695, 160}, vect{90, 35}, sfWhite);
    sc->rect[7] = init_rect(vect{695, 205}, vect{90, 35}, sfWhite);
    sc->rect[8] = init_rect(vect{695, 250}, vect{90, 35}, sfWhite);
    sc->rect[9] = init_rect(vect{250, 400}, size, sfWhite);
    sc->rect[10] = init_rect(vect{400,400}, size, sfWhite);
    sc->rect[11] = init_rect(vect{400, 100}, vect{200, 200}, sfWhite);
    sc->rect[12] = init_rect(vect{160, 125}, size, sfWhite);
    sc->rect[13] = init_rect(vect{160, 165}, size, sfWhite);
    sc->back_file = init_rect(vect{160, 85}, vect{120, 120}, sfTransparent);
}

void init_main_scene(mainScene_t *sc, color_t *clr)
{
    sfVector2f pos = {1, 1};
    sfVector2f size = {798, 498};
    sc->invalid_color = false;

    sc->file_type = ".jpg";
    sc->rect = malloc(sizeof(sfRectangleShape *) * 14);
    sc->text = malloc(sizeof(sfText *) * 22);
    sc->rect[0] = init_rect(pos, size, clr->dk_grey3);
    pos = (sfVector2f){120, 20};
    size = (sfVector2f){250, 35};
    sfRectangleShape_setOutlineThickness(sc->rect[0], 2);
    sfRectangleShape_setOutlineColor(sc->rect[0], sfWhite);
    init_color_buttons(sc, clr, (sfVector2f){120, 30});
    text_main_scene(sc, clr);
    init_input_text(sc);
    init_values_text(sc, clr);
}
