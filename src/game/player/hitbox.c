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
    float posy = floor((player->pos.y) / (16 * 2.2));
    int pos = floor((38 * posy) + posx);

    //printf ("x:%i\ty:%i\t", posx, posy);
    //printf("int:%i  char:%c\n", pos, master->game->board[pos]);
    player->hitbox[0] = master->game->board[pos + 1];
    player->hitbox[1] = master->game->board[pos + 38];
    player->hitbox[2] = master->game->board[pos - 1];
    player->hitbox[3] = master->game->board[pos - 38];
    update_facing_sprite(player, master->game->key);
    set_movement(master, player);
}

void set_movement(master_t *master, player_t *player)
{
    float posx = player->pos.x / (16 * 2.2);
    float posy = player->pos.y / (16 * 2.2);
    //printf ("%f\n", posy - floor(posy));
    if (player->hitbox[0] != '0' && posx - floor(posx) >= 0.5) {
        master->game->key->D = 0;
    }
    if (player->hitbox[1] != '0' && posy - floor(posy) > 0.3) {
        master->game->key->S = 0;
    }
    if (player->hitbox[2] != '0'&& posx - floor(posx) <= 0.5) {
        master->game->key->Q = 0;
    }
    if (player->hitbox[3] != '0'&& posy - floor(posy) <= 0.1) {
        master->game->key->Z = 0;
    }
}