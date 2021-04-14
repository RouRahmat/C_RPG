/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** attack
*/

#include "include.h"

int update_player_attdir(master_t *master, player_t *player)
{
    sfVector2i m = sfMouse_getPosition(master->window);
    sfVector2f m_t = sfRenderWindow_mapPixelToCoords(master->window, m, NULL);
    float atan = atan2(m_t.y - player->pos.y, m_t.x - player->pos.x);
    int angle = atan * 180 / 3.14;

    if (angle >= -45 && angle < 45)
        return (3);
    if (angle >= 45 && angle < 135)
        return (0);
    if (angle >= 135 || angle < -135)
        return (2);
    if (angle >= -135 && angle < -45)
        return (1);
    return (angle);
}

void attack(master_t *master)
{
    master->game->player->rect.top = 16;
    master->game->player->rect.left = 16 * master->game->player->att_dir;
}