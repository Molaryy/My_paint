/*
** EPITECH PROJECT, 2023
** ssl_new_circle
** File description:
** ssl_new_circle
*/

#include "msl.h"

sfCircleShape *ssl_new_cirle(sfData_t data)
{
    sfCircleShape *circ = sfCircleShape_create();

    sfCircleShape_setRadius(circ, data.size.x);
    sfCircleShape_setFillColor(circ, data.color);
    sfCircleShape_setPosition(circ, data.pos);
    return circ;
}
