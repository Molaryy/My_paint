/*
** EPITECH PROJECT, 2023
** event_clipboard
** File description:
** event_clipboard
*/

#include "src.h"

int check_name_text(paint_t *pt, int idx_name)
{
    if (pt->mn_scn->wait != 1)
        return idx_name;
    if (idx_name < 15 && pt->event_main.text.unicode != 8) {
        pt->mn_scn->input[0][idx_name] = (char)pt->event_main.text.unicode;
        sfText_setString(pt->mn_scn->text[10], pt->mn_scn->input[0]);
        idx_name++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_name - 1 >= 0)
            idx_name--;
        pt->mn_scn->input[0][idx_name] = '\0';
        sfText_setString(pt->mn_scn->text[10], pt->mn_scn->input[0]);
    }
    pt->mn_scn->input[0][14] = '\0';
    return idx_name;
}

int check_width_text(paint_t *pt, int idx_width)
{
    if (pt->mn_scn->wait != 2)
        return idx_width;
    if (idx_width < 4 && pt->event_main.text.unicode != 8
    && msl_charisnum(pt->event_main.text.unicode)) {
        pt->mn_scn->input[1][idx_width] = (char)pt->event_main.text.unicode;
        if (idx_width + 1 < 4)
            pt->mn_scn->input[2][idx_width + 1] = '\0';
        sfText_setString(pt->mn_scn->text[11], pt->mn_scn->input[1]);
        idx_width++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_width - 1 >= 0)
            idx_width--;
        pt->mn_scn->input[1][idx_width] = '\0';
        sfText_setString(pt->mn_scn->text[11], pt->mn_scn->input[1]);
    }
    pt->mn_scn->input[1][4] = '\0';
    return idx_width;
}

int check_height_text(paint_t *pt, int idx_height)
{
    if (pt->mn_scn->wait != 3)
        return idx_height;
    if (idx_height < 4 && pt->event_main.text.unicode != 8
    && msl_charisnum(pt->event_main.text.unicode)) {
        pt->mn_scn->input[2][idx_height] = (char)pt->event_main.text.unicode;
        if (idx_height + 1 < 4)
            pt->mn_scn->input[2][idx_height + 1] = '\0';
        sfText_setString(pt->mn_scn->text[12], pt->mn_scn->input[2]);
        idx_height++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_height - 1 >= 0){
            idx_height--;
        }
        pt->mn_scn->input[2][idx_height] = '\0';
        sfText_setString(pt->mn_scn->text[12], pt->mn_scn->input[2]);
    }
    pt->mn_scn->input[2][4] = '\0';
    return idx_height;
}

int check_r_text(paint_t *pt, int idx_r)
{
    if (pt->mn_scn->wait != 4)
        return idx_r;
    if (idx_r < 3 && pt->event_main.text.unicode != 8
    && msl_charisnum(pt->event_main.text.unicode)) {
        pt->mn_scn->input[3][idx_r] = (char)pt->event_main.text.unicode;
        if (idx_r + 1 < 3)
            pt->mn_scn->input[3][idx_r + 1] = '\0';
        sfText_setString(pt->mn_scn->text[13], pt->mn_scn->input[3]);
        idx_r++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_r - 1 >= 0){
            idx_r--;
        }
        pt->mn_scn->input[3][idx_r] = '\0';
        sfText_setString(pt->mn_scn->text[13], pt->mn_scn->input[3]);
    }
    pt->mn_scn->input[3][3] = '\0';
    return idx_r;
}

void input_text(paint_t *pt)
{
    static int idx_name = 0;
    static int idx_width = 0;
    static int idx_height = 0;
    static int idx_r = 0;
    static int idx_g = 0;
    static int idx_b = 0;
    static int idx_a = 0;

    if (pt->scene != 0)
        return;
    if (pt->event_main.type == sfEvtTextEntered) {
        idx_name = check_name_text(pt, idx_name);
        idx_width = check_width_text(pt, idx_width);
        idx_height = check_height_text(pt, idx_height);
        idx_r = check_r_text(pt, idx_r);
        idx_g = check_g_text(pt, idx_g);
        idx_b = check_b_text(pt, idx_b);
        idx_a = check_a_text(pt, idx_a);
    }
}
