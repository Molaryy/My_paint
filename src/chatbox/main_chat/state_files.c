/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

void state_files (paint_t *pt)
{
    sfColor color = sfColor_fromRGB(46,139,87);

    if (mouse_over(pt->mn_scn->rect[2], pt->mouse_main) == true){
        sfText_setColor(pt->mn_scn->text[19], color);
        sfText_setColor(pt->mn_scn->text[20], sfBlack);
        sfText_setColor(pt->mn_scn->text[21], sfBlack);
        pt->mn_scn->file_type = ".jpg";
    }
    if (mouse_over(pt->mn_scn->rect[12], pt->mouse_main) == true){
        pt->mn_scn->file_type = ".bmp";
        sfText_setColor(pt->mn_scn->text[19], sfBlack);
        sfText_setColor(pt->mn_scn->text[20], color);
        sfText_setColor(pt->mn_scn->text[21], sfBlack);
    }
    if (mouse_over(pt->mn_scn->rect[13], pt->mouse_main) == true){
        pt->mn_scn->file_type = ".png";
        sfText_setColor(pt->mn_scn->text[19], sfBlack);
        sfText_setColor(pt->mn_scn->text[20], sfBlack);
        sfText_setColor(pt->mn_scn->text[21], color);
    }
}
