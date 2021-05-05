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

void check_inter_pos(master_t *master)
{
    float posx = floor((master->game->player->pos.x) / (16 * 2.2));
    float posy = floor((master->game->player->pos.y) / (16 * 2.2));
    int pos = floor((38 * posy) + posx) * (1.5 * master->game->loca);
    int i = 0;
    int doors[2] = {877, 198};

    for(; doors[i] != pos && i <= 2; i++);
    if(i <= 1)
        switchmap(master, i+1);
}

void check_interaction(master_t *master)
{
    player_t *player = master->game->player;

    for (int i = 0; i != 4; i++){
        if (player->hitbox[i] == '2' && player->facing == i){
            sfRenderWindow_drawSprite(master->window, player->s_inter, NULL);
            if (igcheck_key_state(master->game->key) == 1)
                check_inter_pos(master);
        }
    }
}

void display(master_t *master)
{
    game_t *game = master->game;
    txtbox_t *txtbox = game->txtbox;

    sfRenderWindow_drawSprite(master->window, game->map, NULL);
    if (master->game->txtbox->disp == 1) {
        sfRenderWindow_drawSprite(master->window, txtbox->sprite, NULL);
        if (master->game->txtbox->status == 1)
            sfRenderWindow_drawSprite(master->window, txtbox->arrow, NULL);
        sfRenderWindow_drawText(master->window, txtbox->text, NULL);
    }
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfRenderWindow_drawSprite(master->window, game->player->sprite, NULL);
    sfRenderWindow_drawSprite(master->window, game->fg_map, NULL);
    check_interaction(master);
    sfRenderWindow_display(master->window);
    sfRenderWindow_clear(master->window, sfTransparent);
}

int game(master_t *master)
{
    check_keys(master);
    update(master);
    display(master);
}