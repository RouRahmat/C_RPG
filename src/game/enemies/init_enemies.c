/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** init_enemies
*/

#include "include.h"

void add_enemy(game_t *game, List *enemies)
{
    Element *element = malloc(sizeof(struct Element));
    sfIntRect rect = {0, 0, 16, 16};
    int pos = 0;

    element->type = my_rand(0, 2);
    while (game->board[pos] != '0')
        pos = my_rand(0, my_strlen(game->board));
    element->rect = rect;
    for (int i = 0; i < 4; i++) {
        element->movement[i] = 0;
        element->hitbox[i] = '0';
    }
    element->sprite = game->enemies->s_en[element->type];
    element->pos.y = (pos / 38) * 35.2;
    element->pos.x = (pos % 38) * 35.2;
    element->anim = 0;
    element->facing = 0;
    element->health = 10;
    ll_insert(enemies, -1, element);
}

void init_enemies(game_t *game)
{
    free(game->enemies->lenemies);
    List *enemies = ll_initialise();
    int i = my_rand(5, 10);

    for (int count = 0; count != i; count++)
        add_enemy(game, enemies);
    ll_delete(enemies, 0);
    game->enemies->lenemies = enemies;
}