/*
** EPITECH PROJECT, 2023
** init_paint.c
** File description:
** init all the values of the paint
*/

#include "src.h"

void expand_pixels(page_t *pg, int x, int y)
{
    if (pg->draw == 0)
        return;
    if (x < pg->width && y < pg->height && x >= 0 && y >= 0){
        pg->pixels[((y * pg->width + x )* 4)] = pg->color.r;
        pg->pixels[((y * pg->width + x )* 4) + 1] = pg->color.g;
        pg->pixels[((y * pg->width + x )* 4) + 2] = pg->color.b;
        pg->pixels[((y * pg->width + x )* 4) + 3] = pg->color.a;
    }
}

static void draw_pencil(page_t *pg, sfVector2i pos_1)
{
    if (pg->color.r == -2)
        return;
    for (int i = -pg->size; i != pg->size; i++){
        for (int j = -pg->size; j != pg->size; j++)
            expand_pixels(pg, pos_1.x + j, pos_1.y + i);
    }
}

void update_pixels(int x, int y, page_t *pg, int i)
{
    for (int j = x - pg->size; j <= x + pg->size; j++)
        if (pow(j - x, 2) + pow(i - y, 2) <= pow(pg->size, 2))
            expand_pixels(pg, j, i);
}

void draw_framebuffer_cercle(page_t *pg, paint_t *pt)
{
    int x = 0;
    int y = 0;
    int mouseX = pt->mouse.x;
    int mouseY = pt->mouse.y;
    sfVector2f pos = sfSprite_getPosition(pg->page);

    if (pt->scene == 0)
        return;
    pos.x -= pg->width / 2;
    pos.y -= pg->height / 2;
    mouseX -= pos.x;
    mouseY -= pos.y;
    x = mouseX;
    y = mouseY;
    for (int i = y - pg->size; i <= y + pg->size; i++)
        update_pixels(x, y, pg, i);
    sfTexture_updateFromPixels(pt->pg->texture, pt->pg->pixels,
    pt->pg->width, pt->pg->height, 0, 0);
}

void update_pixels_2(sfVector2i pos_1,
sfVector2i pos_2, page_t *pg, paint_t *pt)
{
    int dx = abs(pos_2.x - pos_1.x);
    int dy = abs(pos_2.y - pos_1.y);
    int sx = pos_1.x < pos_2.x ? 1 : -1;
    int sy = pos_1.y < pos_2.y ? 1 : -1;
    int err = dx - dy;
    int e2 = 0;
    while (1) {
        draw_pencil(pg, pos_1);
        if (pos_1.x == pos_2.x && pos_1.y == pos_2.y)
            break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            pos_1.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            pos_1.y += sy;
        }
    }
}
