/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** update
*/

#include "include.h"

void update_facing_sprite(player_t *player, keyboard_t *key)
{
    if (key->Z == 1)
        player->rect.left = 16;
    if (key->Q == 1)
        player->rect.left = 32;
    if (key->S == 1)
        player->rect.left = 0;
    if (key->D == 1)
        player->rect.left = 48;
}

sfVector2f update_player_pos(master_t *master, player_t *player, keyboard_t *key)
{
    sfVector2f pos = {0, 0};
    pos.x = player->pos.x + 3 * key->D - 3 * key->Q;
    pos.y = player->pos.y + 3 * key->S - 3 * key->Z;
    return (pos);
}

int update_player_facing(player_t *player)
{
    if (player->rect.left == 0)
        return (1);
    if (player->rect.left == 16)
        return (3);
    if (player->rect.left == 32)
        return (2);
    return (0);
}

void player_anim(master_t *master, player_t *player, keyboard_t *key)
{
    static int anim = 0;
    if ((key->Z || key->Q || key->S || key->D) && anim >= 10){
        anim = 0;
        player->rect.top += 16;
        if (player->rect.top >= 64)
            player->rect.top = 0;
    }
    else if (anim >= 10) {
            anim = 0;
            player->rect.top = 0;
    }
    anim++;
}

void player(master_t *master, player_t *player)
{
    sfIntRect rec = {0, 0, 16, 16};
    sfVector2f or = {rec.left + (rec.width / 2), rec.top + (rec.height / 2)};
    sfSprite_setOrigin(player->sprite, or);

    player->facing = update_player_facing(player);
    update_hitbox(master, player);
    player->pos = update_player_pos(master, player, master->game->key);
    player->att_dir = update_player_attdir(master, player);
    player_anim(master, player, master->game->key);
    for (int i = 0; i != 4; i++)
        if (player->hitbox[i] == '2' && player->facing == i) {
            update_int_button(master, player);
        }
}