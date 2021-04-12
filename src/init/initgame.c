/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** initgame
*/

#include "../include/include.h"

sfSprite *setmap(void)
{
    sfVector2f scale = {2.2, 2.2};
    sfVector2f pos = {-250, -50};
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("asset/game/map.png", NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

player_t *setplayer(void)
{
    sfVector2f scale = {3, 3};
    sfVector2f pos = {750, 400};
    sfIntRect rect = {0, 0, 16, 16};
    player_t *player = malloc(sizeof(player_t));
    sfTexture *texture = sfTexture_createFromFile("asset/characters/main.png", NULL);
    player->sprite = sfSprite_create();
    player->pos = pos;
    player->rect = rect;
    sfSprite_setTexture(player->sprite, texture, sfFalse);
    sfSprite_setScale(player->sprite, scale);
    sfSprite_setPosition(player->sprite, pos);
    sfSprite_setTextureRect(player->sprite, rect);
    return (player);
}

keyboard_t *setkey(void)
{
    keyboard_t *key = malloc(sizeof(keyboard_t));

    key->Z = 0;
    key->Q = 0;
    key->S = 0;
    key->D = 0;
    key->E = 0;
    key->I = 0;
    key->Mouse = 0;
    return (key);
}

game_t *setgame(void)
{
    char defaulttxt[] = "\0";
    sfTexture *texture = sfTexture_createFromFile("asset/game/txtbox.png", NULL);
    sfTexture *t_arrow = sfTexture_createFromFile("asset/game/arrow.png", NULL);
    sfVector2f scale = {3, 3};
    sfVector2f pos = {166, 540};
    sfVector2f arrowpos = {1050, 660};
    sfVector2f txtpos = {200, 535};
    sfFont *font = sfFont_createFromFile("asset/Silver.ttf");
    game_t *game = malloc(sizeof(game_t));

    game->map = setmap();
    game->player = setplayer();
    game->key = setkey();
    game->txtbox = malloc(sizeof(txtbox_t));
    game->txtbox->sprite = sfSprite_create();
    game->txtbox->arrow = sfSprite_create();
    game->txtbox->text = sfText_create();
    game->txtbox->string = defaulttxt;
    game->txtbox->disp = 0;
    sfText_setFont(game->txtbox->text, font);
    sfText_setLineSpacing(game->txtbox->text, 0.75);
    sfText_setCharacterSize(game->txtbox->text, 60);
    sfText_setColor(game->txtbox->text, sfBlack);
    sfText_setPosition(game->txtbox->text, txtpos);

    sfSprite_setScale(game->txtbox->sprite, scale);
    sfSprite_setPosition(game->txtbox->sprite, pos);

    sfSprite_setScale(game->txtbox->arrow, scale);
    sfSprite_setPosition(game->txtbox->arrow, arrowpos);

    sfSprite_setTexture(game->txtbox->sprite, texture, sfTrue);
    sfSprite_setTexture(game->txtbox->arrow, t_arrow, sfTrue);
    return (game);
}