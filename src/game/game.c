/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** game
*/

#include "include.h"

void update(master_t *master)
{
    player(master, master->game->player);
}

void display(master_t *master)
{
    sfRenderWindow_drawSprite(master->window, master->game->map, NULL);
    if (master->game->txtbox->disp == 1) {
        sfRenderWindow_drawSprite(master->window, master->game->txtbox->sprite, NULL);
        if (master->game->txtbox->status == 1)
            sfRenderWindow_drawSprite(master->window, master->game->txtbox->arrow, NULL);
        sfRenderWindow_drawText(master->window, master->game->txtbox->text, NULL);
    }
    sfSprite_setTextureRect(master->game->player->sprite, master->game->player->rect);
    sfSprite_setPosition(master->game->player->sprite, master->game->player->pos);
    sfRenderWindow_drawSprite(master->window, master->game->player->sprite, NULL);
    sfRenderWindow_drawSprite(master->window, master->game->fg_map, NULL);
    for (int i = 0; i != 4; i++)
        if (master->game->player->hitbox[i] == '2' && master->game->player->facing == i)
            sfRenderWindow_drawSprite(master->window, master->game->player->s_inter, NULL);
    sfRenderWindow_display(master->window);
    sfRenderWindow_clear(master->window, sfTransparent);
}

int game(master_t *master)
{
    //ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
    check_keys(master);
    //printf ("Z : %i\tQ : %i\tS : %i\tD : %i\tE : %i\tI : %i\t Click : %i\n", master->game->key->Z, master->game->key->Q, master->game->key->S, master->game->key->D, master->game->key->E, master->game->key->I, master->game->key->Mouse);
    //txtbox_settext(master->game->txtbox, 0, "test");
    update(master);
    display(master);
}