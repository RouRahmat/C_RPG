/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** hitbox
*/

#include "include.h"

void update_enemy_htbx(game_t *game, Element *node)
{
    float posx = floor((node->pos.x) / (16 * 2.2));
    float posy = floor((node->pos.y + 25) / (16 * 2.2));
    int pos = floor((38 * posy) + posx);

    node->hitbox[0] = game->board[pos + 1];
    node->hitbox[1] = game->board[pos];
    node->hitbox[2] = game->board[pos - 1];
    node->hitbox[3] = game->board[pos - 38];
}