/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** update
*/

#include "include.h"

void update_facing_sprite(player_t *player, keyboard_t *key)
{
    if (player->hit == 0) {
        if (key->Z == 1)
            player->rect.left = 16;
        if (key->Q == 1)
            player->rect.left = 32;
        if (key->S == 1)
            player->rect.left = 0;
        if (key->D == 1)
            player->rect.left = 48;
    }
}

void update_player_pos(master_t *master, player_t *player, keyboard_t *key)
{
    //if (player->hit != 1)
        player->pos.x += 3 * key->D - 3 * key->Q;
        player->pos.y += 3 * key->S - 3 * key->Z;
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

void update_hit(List *lenemies, player_t *player, keyboard_t *key)
{
    static int timer = 0;
    for (Element *node = lenemies->first; node != NULL && player->hit == 0 && node->type != -1; node = node->next)
        if (node->pos.y > player->pos.y - 20 && node->pos.y < player->pos.y + 20 )
            if (node->pos.x > player->pos.x - 20 && node->pos.x < player->pos.x + 20) {
                player->hit = 1;
                timer = 0;
            }
    if (player->hit == 1) {
        if (timer >= 30)
            player->hit = 0;
            key->D = 1;
            key->Z = 0;
            key->Q = 0;
            key->S = 0;
        player->rect.left = 16;
        player->rect.top = 96;
        timer++;
    }
}

void check_attack(master_t *master, player_t *player, keyboard_t *key)
{
    static int timer = -1;

    if (igcheck_mouse_state() == 1 && timer == -1)
        timer = 0;
    if (timer >= 0) {
        attack(master);
        player->atk = 1;
        timer++;
    }
    if (timer >= 8) {
        player->atk = 0;
        timer = -1;
    }
}

void player(master_t *master, player_t *player)
{
    sfIntRect rec = {0, 0, 16, 16};
    sfVector2f or = {rec.left + (rec.width / 2), rec.top + (rec.height / 2)};
    sfSprite_setOrigin(player->sprite, or);

    update_hit(master->game->enemies->lenemies, player, master->game->key);
    update_hitbox(master, player);
    update_player_pos(master, player, master->game->key);
    //printf ("%i\n", master->game->key->Mouse);
    if (player->hit != 1) {
    player->facing = update_player_facing(player);
        player->att_dir = update_player_attdir(master, player);
        player_anim(master, player, master->game->key);
        check_attack(master, master->game->player, master->game->key);
        for (int i = 0; i != 4; i++)
            if (player->hitbox[i] == '2' && player->facing == i) {
                update_int_button(master, player);
            }
    }
}