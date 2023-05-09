/*
** EPITECH PROJECT, 2023
** event_clipboard
** File description:
** event_clipboard
*/

#include "src.h"
#include <dirent.h>

bool find_str_in_str(char *src, char *to_find)
{
    int j = 0;

    for (int i = 0; src[i] != '\0'; i++){
        if (to_find[j] != '\0' && src[i] == to_find[j])
            j++;
    }
    if (j == msl_strlen(to_find))
        return true;
    return false;
}

void create_file(paint_t *pt)
{
    DIR *dir = opendir("save");
    sfImage *img = sfImage_createFromPixels(pt->pg->width,
    pt->pg->height, pt->pg->pixels);
    FILE *file;
    char *example = "Example";

    if (pt->mn_scn->input[0][0] == '\0')
        pt->mn_scn->input[0] = example;
    if (find_str_in_str(pt->mn_scn->input[0], pt->mn_scn->file_type) == false){
        if (dir != NULL)
            pt->mn_scn->input[0] = msl_strcat("save/", pt->mn_scn->input[0]);
        pt->mn_scn->input[0] = msl_strcat(pt->mn_scn->input[0],
        pt->mn_scn->file_type);
    }
    file = fopen(pt->mn_scn->input[0], "wb");
    sfImage_saveToFile(img, pt->mn_scn->input[0]);
}
