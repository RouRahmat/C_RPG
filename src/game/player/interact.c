/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** interact
*/

#include "include.h"

void update_int_button(master_t *master, player_t *player)
{
    static int anim = 0;
    static int ymovement = 50;
    sfVector2f pos = {player->pos.x + 20, player->pos.y - ymovement};

    if (anim >= 50) {
        if (ymovement == 45)
            ymovement = 50;
        else
            ymovement = 45;
        anim = 0;
    }
    pos.y = player->pos.y - ymovement;
    anim++;
    sfSprite_setPosition(player->s_inter, pos);
}