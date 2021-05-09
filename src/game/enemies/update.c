/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** update
*/

#include "include.h"

void update_enemy_mvmt(Element *node)
{
    int rand = my_rand(0, 20);
    if (rand < 4) {
        for (int i = 0; i < 4; i++)
            node->movement[i] = 0;
        node->movement[rand] = 1;
    }
    else if (rand < 8)
        for (int i = 0; i < 4; i++)
            node->movement[i] = 0;
    if (node->hitbox[0] != '0')
        node->movement[3] = 0;
    if (node->hitbox[1] != '0')
        node->movement[0] = 0;
    if (node->hitbox[2] != '0')
        node->movement[2] = 0;
    if (node->hitbox[3] != '0')
        node->movement[1] = 0;
}

sfVector2f update_facing_enemy(Element *node)
{
    sfVector2f pos = {0, 0};
    for (int i = 0; i < 4; i++)
        if (node->movement[i] == 1)
            node->rect.left = 16 * i;
    pos.y = node->pos.y + node->movement[0] - node->movement[1];
    pos.x = node->pos.x + node->movement[3] - node->movement[2];
    return (pos);
}

int update_enemy_anim(Element *node)
{
    update_enemy_mvmt(node);
    for (int i = 0; i < 4; i++) {
        if (node->movement[i] != 0) {
            node->rect.top += 16;
            if (node->rect.top >= 64)
                node->rect.top = 0;
            node->anim = 0;
            return (0);
        }
    }
    node->rect.top = 0;
}

void update_enemy(Element *node)
{
    node->pos = update_facing_enemy(node);
    if (node->anim >= 10) {
        update_enemy_anim(node);
        node->anim = 0;
    }
    node->anim++;
}

void update_enemies(game_t *game, List *lenemies)
{
    for (Element *node = lenemies->first; node != NULL && node->type != -1; node = node->next) {
        update_enemy_htbx(game, node);
        update_enemy(node);
    }
}