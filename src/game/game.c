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
    update_enemies(master->game, master->game->enemies->lenemies);
}

void check_inter_pos(master_t *master)
{
    float posx = floor((master->game->player->pos.x) / (16 * 2.2));
    float posy = floor((master->game->player->pos.y) / (16 * 2.2));
    int pos = floor((38 * posy) + posx) * (1.5 * master->game->loca);
    int i = 0;
    int doors[2] = {877, 396};
    
    for(; doors[i] != pos && i <= 2; i++);
    if(i == 0)
        switchmap(master, my_rand(2, 4));
    else
        switchmap(master, 1);
}

void check_interaction(master_t *master)
{
    for (int i = 0; i != 4; i++){
        if (master->game->player->hitbox[i] == '2' && master->game->player->facing == i){
            sfRenderWindow_drawSprite(master->window, master->game->player->s_inter, NULL);
            if(igcheck_key_state(master->game->key) == 1)
                check_inter_pos(master);
        }
    }
}

void draw_atk (master_t *master, player_t *player) {
    sfVector2f pos = {player->pos.x, player->pos.y};
    sfIntRect rect = {10 * player->facing, 0, 10, 10};

    if (player->facing == 0)
        pos.x += 14;
    if (player->facing == 2)
        pos.x -= 42;
    if (player->facing == 1)
        pos.y += 14;
    if (player->facing == 3)
        pos.y -= 28;
    if (player->atk == 1) {
        sfSprite_setPosition(player->s_sword, pos);
        sfSprite_setTextureRect(player->s_sword, rect);
        sfRenderWindow_drawSprite(master->window, player->s_sword, NULL);
    }
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

    for (Element *node = master->game->enemies->lenemies->first; node != NULL && node->type != -1; node = node->next) {
        if (node->pos.y < master->game->player->pos.y) {
        sfSprite_setTextureRect(node->sprite, node->rect);
        sfSprite_setPosition(node->sprite, node->pos);
        sfRenderWindow_drawSprite(master->window, node->sprite, NULL);
        }
    }
    sfRenderWindow_drawSprite(master->window, master->game->player->sprite, NULL);
    draw_atk(master, master->game->player);
    for (Element *node = master->game->enemies->lenemies->first; node != NULL && node->type != -1; node = node->next) {
        if (node->pos.y >= master->game->player->pos.y) {
        sfSprite_setTextureRect(node->sprite, node->rect);
        sfSprite_setPosition(node->sprite, node->pos);
        sfRenderWindow_drawSprite(master->window, node->sprite, NULL);
        }
    }
    sfRenderWindow_drawSprite(master->window, master->game->fg_map, NULL);
    check_interaction(master);
    sfRenderWindow_display(master->window);
    sfRenderWindow_clear(master->window, sfTransparent);
}

int game(master_t *master)
{
    //ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
    check_keys(master);
    //printf ("Z : %i\tQ : %i\tS : %i\tD : %i\tE : %i\tI : %i\t Click : %i\n", master->game->key->Z, master->game->key->Q, master->game->key->S, master->game->key->D, master->game->key->E, master->game->key->I, master->game->key->Mouse);
    //txtbox_settext(master->game->txtbox, 0, "test");
    //printf("pos = %f\n", master->game->player->pos.y);
    update(master);
    display(master);
}