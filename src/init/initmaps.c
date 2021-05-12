/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** initmaps
*/

#include "include.h"

void addmap(maps_t *maps, sfVector2f m_pos, sfVector2f p_pos, char *c_path)
{
    map_t *new_map = malloc(sizeof(map_t));

    new_map->collisionpath = c_path;
    new_map->m_pos = m_pos;
    new_map->p_pos = p_pos;
    new_map->next = maps->first;
    maps->first = new_map;
    if(new_map->next)
        new_map->loca = new_map->next->loca + 1;
    else
        new_map->loca = 1;
}

maps_t *setmaps(void)
{
    maps_t *maps = malloc(sizeof(maps));
    sfVector2f p_pos = {551, 529};
    sfVector2f m_pos = {-246, -68};

    addmap(maps, m_pos, p_pos, "asset/game/map.txt");
    p_pos.x = 650;
    p_pos.y = 120;
    m_pos.x = 0;
    m_pos.y = -2746;
    addmap(maps, m_pos, p_pos, "asset/game/dj1.txt");
    m_pos.x = -1375;
    m_pos.y = -2746;
    addmap(maps, m_pos, p_pos, "asset/game/dj2.txt");
    m_pos.x = -2750;
    m_pos.y = -2746;
    addmap(maps, m_pos, p_pos, "asset/game/dj3.txt");
    return (maps);
}