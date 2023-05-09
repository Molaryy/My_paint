/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

void init_colors(color_t *clr)
{
    clr->lt_grey = sfColor_fromRGB(59, 61, 63);
    clr->lt_blue = sfColor_fromRGB(50, 130, 246);
    clr->lt_green = sfColor_fromRGB(161, 251, 142);
    clr->grey = sfColor_fromRGB(210, 210, 212);
    clr->lt_red = sfColor_fromRGB(171, 86, 86);
    clr->lt_yellow = sfColor_fromRGB(255, 251, 184);
    clr->orange = sfColor_fromRGB(240, 134, 80);
    clr->pink = sfColor_fromRGB(239, 136, 190);
    clr->purple = sfColor_fromRGB(116, 27, 124);
    clr->dk_grey1 = sfColor_fromRGB(49, 50, 52);
    clr->dk_grey2 = sfColor_fromRGB(44, 47, 48);
    clr->dk_grey3 = sfColor_fromRGB(43, 42, 47);
    clr->dk_red = sfColor_fromRGB(139, 0, 0);
    clr->blue = sfColor_fromRGB(173, 216, 230);
    clr->lt_orange = sfColor_fromRGB(255, 213, 128);
    clr->brown = sfColor_fromRGB(128, 84, 0);
}
