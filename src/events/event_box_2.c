/*
** EPITECH PROJECT, 2023
** event_clipboard
** File description:
** event_clipboard
*/

#include "src.h"

int check_g_text(paint_t *pt, int idx_g)
{
    if (pt->mn_scn->wait != 5)
        return idx_g;
    if (idx_g < 3 && pt->event_main.text.unicode != 8
    && msl_charisnum(pt->event_main.text.unicode)) {
        pt->mn_scn->input[4][idx_g] = (char)pt->event_main.text.unicode;
        if (idx_g + 1 < 3)
            pt->mn_scn->input[4][idx_g + 1] = '\0';
        sfText_setString(pt->mn_scn->text[14], pt->mn_scn->input[4]);
        idx_g++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_g - 1 >= 0)
            idx_g--;
        pt->mn_scn->input[4][idx_g] = '\0';
        sfText_setString(pt->mn_scn->text[14], pt->mn_scn->input[4]);
    }
    pt->mn_scn->input[4][3] = '\0';
    return idx_g;
}

int check_b_text(paint_t *pt, int idx_b)
{
    if (pt->mn_scn->wait != 6)
        return idx_b;
    if (idx_b < 3 && pt->event_main.text.unicode != 8
    && msl_charisnum(pt->event_main.text.unicode)) {
        pt->mn_scn->input[5][idx_b] = (char)pt->event_main.text.unicode;
        if (idx_b + 1 < 3)
            pt->mn_scn->input[5][idx_b + 1] = '\0';
        sfText_setString(pt->mn_scn->text[15], pt->mn_scn->input[5]);
        idx_b++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_b - 1 >= 0)
            idx_b--;
        pt->mn_scn->input[5][idx_b] = '\0';
        sfText_setString(pt->mn_scn->text[15], pt->mn_scn->input[5]);
    }
    pt->mn_scn->input[5][3] = '\0';
    return idx_b;
}

int check_a_text(paint_t *pt, int idx_a)
{
    if (pt->mn_scn->wait != 7)
        return idx_a;
    if (idx_a < 3 && pt->event_main.text.unicode != 8
    && msl_charisnum(pt->event_main.text.unicode)) {
        pt->mn_scn->input[6][idx_a] = (char)pt->event_main.text.unicode;
        if (idx_a + 1 < 3)
            pt->mn_scn->input[6][idx_a + 1] = '\0';
        sfText_setString(pt->mn_scn->text[16], pt->mn_scn->input[6]);
        idx_a++;
    }
    if (pt->event_main.text.unicode == 8) {
        if (idx_a - 1 >= 0)
            idx_a--;
        pt->mn_scn->input[6][idx_a] = '\0';
        sfText_setString(pt->mn_scn->text[16], pt->mn_scn->input[6]);
    }
    pt->mn_scn->input[6][3] = '\0';
    return idx_a;
}
