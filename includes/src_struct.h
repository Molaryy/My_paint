/*
** EPITECH PROJECT, 2023
** src_struct
** File description:
** src_struct
*/

#ifndef SRC_STRUCT
    #define SRC_STRUCT
    #include <stdbool.h>
    #include "csl_struct.h"
    #define sl sfSprite_setScale
    #define so sfSprite_setOrigin
    #define rs sfRectangleShape_setScale
    #define ro sfRectangleShape_setOrigin

typedef struct sfData_s{
    sfVector2f pos;
    void **obj;
    sfText *text;
    sfVector2f size;
    sfFont *font;
    int state;
    char *path;
    sfColor color;
}sfData_t;

typedef struct cliboard_s {

} clipboard_t;

typedef struct image_s {

} image_t;

typedef struct tools_s {
    int old_i;
    void *old_tool;
    sfColor pen_color;
    sfColor earase_color;
    int old_sel;
    void *old_pan;
} tools_t;

typedef struct brushes_s {

} brushes_t;

typedef struct shapes_s {

} shapes_t;

typedef struct brushSize_s {

} brushSize_t;

typedef struct colorPanel_s {
    void *old_color;
} colorPanel_t;

typedef struct button_s{

}button_t;

typedef struct bottombar_s {
    sfText **text;
}bottombar_t;

typedef struct toolbar_s{
    sfFont *font;
    sfRectangleShape *tb_rect;
    clipboard_t *cp_b;
    image_t *img;
    tools_t *tools;
    brushes_t *brush;
    shapes_t *shp;
    brushSize_t *size;
    colorPanel_t *cpn;
}toolbar_t;

typedef struct page_s {
    sfVector2i preMouse;
    int width;
    int height;
    sfSprite *page;
    sfVector2f scale;
    sfUint8 *pixels;
    sfTexture *texture;
    sfVector2f pos;
    sfColor color;
    int draw;
    float size;
} page_t;

typedef struct color_s {
    sfColor pink;
    sfColor grey;
    sfColor purple;
    sfColor lt_blue;
    sfColor lt_red;
    sfColor orange;
    sfColor lt_green;
    sfColor lt_grey;
    sfColor lt_yellow;
    sfColor dk_grey1;
    sfColor dk_grey2;
    sfColor dk_grey3;
    sfColor blue;
    sfColor lt_orange;
    sfColor dk_red;
    sfColor brown;
} color_t;

typedef struct button_paint_s {
    bool is_eraser;
    bool is_pencil;
    bool is_bucket;
    sfRectangleShape **rect;
    sfText **text;
    bool is_file_back;
    bool is_file;
    bool is_edit;
    bool is_edit_back;
    bool is_help;
    bool is_help_back;
} button_paint_t;

typedef struct openScene_s {
    bool file_exits;
    sfRectangleShape **rect;
    sfText **text;
    char *input;
} openScene_t;

typedef struct mainScene_s {
    char *file_type;
    bool is_back_file;
    sfRectangleShape *back_file;
    bool invalid_color;
    sfRectangleShape **rect;
    sfText **text;
    char **data;
    char **input;
    int wait;
} mainScene_t;

typedef struct paint_s {

    sfRenderWindow *wd_open;
    sfEvent event_open;
    sfVector2i mouse_open;

    sfRenderWindow *wd;
    sfEvent event;
    sfVector2i mouse;

    sfRenderWindow *wd_main;
    sfEvent event_main;
    sfVector2i mouse_main;


    button_paint_t *bpt;
    openScene_t * op_sn;
    mainScene_t *mn_scn;
    sfData_t *data;
    page_t *pg;
    toolbar_t *tb;
    bottombar_t *btm_b;
    button_t *bt;
    color_t *clr;
    int scene;
    sfTexture *eraser;
    sfTexture *pencil;
    sfTexture *bucket;
    sfSprite *cursor;
} paint_t;

#endif /* !SRC_STRUCT */
