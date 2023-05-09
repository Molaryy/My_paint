/*
** EPITECH PROJECT, 2023
** init_pencil
** File description:
** init_pencil
*/

#include "src.h"

void calc_buffer_line(paint_t *pt, page_t *pg, int mouseX, int mouseY)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        update_pixels_2((sfVector2i){pg->preMouse.x, pg->preMouse.y},
        (sfVector2i){mouseX, mouseY}, pg, pt);
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        pg->preMouse.x = mouseX;
        pg->preMouse.y = mouseY;
    }
    sfTexture_updateFromPixels(pg->texture, pg->pixels,
    pg->width, pg->height, 0, 0);
}

void draw_framebuffer_line(page_t *pg, paint_t *pt)
{
    int mouseX = pt->mouse.x;
    int mouseY = pt->mouse.y;
    sfVector2f pos = sfSprite_getPosition(pg->page);

    if (pt->scene == 0 || pg->color.r < 0)
        return;
    pos.x -= pg->width / 2;
    pos.y -= pg->height / 2;
    mouseX -= pos.x;
    mouseY -= pos.y;
    if (!sfMouse_isButtonPressed(sfMouseLeft)){
        pg->preMouse.x = mouseX;
        pg->preMouse.y = mouseY;
        return;
    }
    calc_buffer_line(pt, pg, mouseX, mouseY);
}

void init_objects(sfData_t *data, page_t *pg, color_t *clr)
{
    init_page(pg);
    sfVector2f size = {1920, 40};
    sfVector2f pos = {0, 0};

    data[0] = (sfData_t){pos, NULL, NULL, size,
    NULL, 0, NULL, clr->dk_grey3};
    data[0].obj = malloc(sizeof(sfRectangleShape *));
    data[0].obj[0] = ssl_new_rect(data[0]);
    size = (sfVector2f){1920, 30};
    pos = (sfVector2f){0, 1050};
    data[1] = (sfData_t){pos, NULL, NULL, size, NULL,
    0, NULL, clr->dk_grey3};
    data[1].obj = malloc(sizeof(sfRectangleShape *));
    data[1].obj[0] = ssl_new_rect(data[1]);
    data[2] = (sfData_t){pos, NULL, NULL, size, NULL, 0, NULL, sfBlack};
    data[2].obj = malloc(sizeof(sfSprite *));
    data[2].obj[0] = pg->page;
}

void init_page(page_t *pg)
{
    pg->size = 2;
    pg->color = sfBlack;
    pg->pos = (sfVector2f){580, 580};
    pg->width = 1080;
    pg->height = 720;
    pg->texture = sfTexture_create(pg->width, pg->height);
    pg->pixels = malloc(sizeof(sfUint8) * pg->width * pg->height * 4);
    memset(pg->pixels, 255, pg->width * pg->height * 4);
    sfTexture_updateFromPixels(pg->texture, pg->pixels, pg->width,
    pg->height, 0, 0);
    pg->page = sfSprite_create();
    pg->scale = (sfVector2f){1, 1};
    sfSprite_setOrigin(pg->page, (sfVector2f){pg->width / 2, pg->height / 2});
    sfSprite_setTexture(pg->page, pg->texture, sfTrue);
    sfSprite_setPosition(pg->page, pg->pos);
}
