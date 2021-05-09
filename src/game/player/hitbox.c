/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** hitbox
*/

#include "include.h"

void update_hitbox(master_t *master, player_t *player)
{
    float posx = floor((player->pos.x) / (16 * 2.2));
    float posy = floor((player->pos.y + 22) / (16 * 2.2));
    int pos = floor((38 * posy) + posx);
    posx = floor((player->pos.x + 19.8) / (16 * 2.2));
    posy = floor((player->pos.y + 19.8) / (16 * 2.2));
    int posleft = floor((38 * posy) + posx);
    posx = floor((player->pos.x - 17.6) / (16 * 2.2));
    int posright = floor((38 * posy) + posx);

    player->hitbox[0] = master->game->board[posright + 1];
    player->hitbox[1] = master->game->board[pos];
    player->hitbox[2] = master->game->board[posleft - 1];
    player->hitbox[3] = master->game->board[pos - 38];
    player->hitbox[4] = master->game->board[pos];
    //printf("  %c\n%c   %c\n  %c\n\n", player->hitbox[3], player->hitbox[2], player->hitbox[0], player->hitbox[1]);
    update_facing_sprite(player, master->game->key);
    set_movement(master, player);
}

void set_movement(master_t *master, player_t *player)
{
    float posx = player->pos.x / (16 * 2.2);
    float posy = player->pos.y / (16 * 2.2);
    int col = player->hitbox[4] - 48;
    //printf ("col: %i\n", col);
    //printf ("%f\n", posy - floor(posy));
    if (player->hitbox[0] != '0' && posx - floor(posx) >= 0.5)
        master->game->key->D = 0;
    if (player->hitbox[1] != '0')
        master->game->key->S = 0;
    if (player->hitbox[2] != '0' && posx - floor(posx) <= 0.5)
        master->game->key->Q = 0;
    if (player->hitbox[3] != '0' && posy - floor(posy) <= 0.1)
        master->game->key->Z = 0;
}