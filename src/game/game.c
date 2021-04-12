/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** game
*/

#include "../include/include.h"

void txtbox_settext(txtbox_t *txtbox, int pos, char *str)
{
    int lenght = my_strlen(str) - pos;
    int arrow = 0;
    int i = 0;
    char line1[145];

    txtbox->status = 0;
    if (lenght > 140) {
        txtbox->status = 1;
        arrow = 4;
    }
    for (; i != lenght && i != 142 - arrow; i++, pos++) {
        if (i == 46 || i == 93) {
            line1[i] = '\n';
            i++;
        }
        line1[i] = str[pos];
    }
    line1[i] = '\0';
    sfText_setString(txtbox->text, line1);
}

int update_facing(master_t *master, player_t *player)
{
    sfVector2i m = sfMouse_getPosition(master->window);
    sfVector2f m_t = sfRenderWindow_mapPixelToCoords(master->window, m, NULL);
    float atan = atan2(m_t.y - player->pos.y, m_t.x - player->pos.x);
    int angle = atan * 180 / 3.14;

    if (angle >= -45 && angle < 45)
        return (1);
    if (angle >= 45 && angle < 135)
        return (2);
    if (angle >= 135 || angle < -135)
        return (3);
    if (angle >= -135 && angle < -45)
        return (4);
    return (angle);
}

sfVector2f update_player(master_t *master, player_t *player, keyboard_t *key)
{
    sfVector2f pos = {0, 0};
    pos.x = player->pos.x + 3 * key->D - 3 * key->Q;
    pos.y = player->pos.y + 3 * key->S - 3 * key->Z;
    if (key->Z == 1)
        player->rect.left = 16;
    if (key->Q == 1)
        player->rect.left = 32;
    if (key->S == 1)
        player->rect.left = 0;
    if (key->D == 1)
        player->rect.left = 48;
    return (pos);
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
    printf ("%.0f\n", player->pos.x / (16 * 3));
    anim++;
}

void player(master_t *master, player_t *player)
{
    sfIntRect rec = {0, 0, 16, 16};
    sfVector2f or = {rec.left + (rec.width / 2), rec.top + (rec.height / 2)};
    sfSprite_setOrigin(player->sprite, or);

    player->pos = update_player(master, player, master->game->key);
    player->facing = update_facing(master, player);
    //printf ("%i\n", player->facing);
    player_anim(master, player, master->game->key);
}

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
    sfRenderWindow_display(master->window);
    sfRenderWindow_clear(master->window, sfTransparent);
}

void defkey(keyboard_t *key)
{
    key->Z = 0;
    key->Q = 0;
    key->S = 0;
    key->D = 0;
    key->E = 0;
    key->I = 0;
    key->Mouse = 0;
}

void check_keys(keyboard_t *key)
{
    defkey(key);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && key->Z == 0)
        key->Z = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && key->Q == 0)
        key->Q = 1;
    if (sfKeyboard_isKeyPressed(sfKeyS) && key->S == 0)
        key->S = 1;
    if (sfKeyboard_isKeyPressed(sfKeyD) && key->D == 0)
        key->D = 1;
    if (sfKeyboard_isKeyPressed(sfKeyE) && key->E == 0)
        key->E = 1;
    if (sfKeyboard_isKeyPressed(sfKeyI) && key->I == 0)
        key->I = 1;
    if (sfMouse_isButtonPressed(sfMouseLeft) && key->Mouse == 0)
        key->Mouse = 1;
}

int game(master_t *master)
{
    //ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
    check_keys(master->game->key);
    //printf ("Z : %i\tQ : %i\tS : %i\tD : %i\tE : %i\tI : %i\t Click : %i\n", master->game->key->Z, master->game->key->Q, master->game->key->S, master->game->key->D, master->game->key->E, master->game->key->I, master->game->key->Mouse);
    //txtbox_settext(master->game->txtbox, 0, "test");
    update(master);
    display(master);
}