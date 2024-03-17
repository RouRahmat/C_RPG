/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** changemaps
*/

#include "include.h"

void switchmap(master_t *master, int i)
{
    map_t *n_map = master->game->maps->first;
printf("i = %d\n", i);
    for (; n_map->loca != i && n_map->next != NULL; n_map = n_map->next)
        printf("n_map = %d\n%s\n", n_map->loca, n_map->collisionpath);
    sfSprite_setPosition(master->game->map, n_map->m_pos);
    sfSprite_setPosition(master->game->fg_map, n_map->m_pos);
    sfSprite_setPosition(master->game->player->sprite, n_map->p_pos);
    get_map(master->game, n_map->collisionpath);
    master->game->loca = n_map->loca;
    master->game->player->pos.x = n_map->p_pos.x;
    master->game->player->pos.y = n_map->p_pos.y;
    if(master->game->loca >= 2)
        init_enemies(master->game);
    else {
        free(master->game->enemies->lenemies);
        master->game->enemies->lenemies = ll_initialise();
    }
}