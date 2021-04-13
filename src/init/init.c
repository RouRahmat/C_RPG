/*
** EPITECH PROJECT, 2021
** bu B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** init
*/

#include "include.h"

sfRenderWindow *init_window(void)
{
    sfVideoMode video_mode = {1280, 720, 30};
    sfRenderWindow *window;
    window = sfRenderWindow_create(video_mode, "my_rpg", sfClose, NULL);

    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    return (window);
}

sfCircleShape *create_circle_entity(sfVector2f vec1, float radius)
{
    sfCircleShape *shape = sfCircleShape_create();
    sfVector2f origin = {radius * 10, radius * 10};

    sfCircleShape_setRadius(shape, 10 * radius);
    sfCircleShape_setOutlineThickness(shape, 4);
    sfCircleShape_setOutlineColor(shape, sfWhite);
    sfCircleShape_setFillColor(shape, sfTransparent);
    sfCircleShape_setOrigin(shape, origin);
    sfCircleShape_setPosition(shape, vec1);
    return (shape);
}