/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Keyboard.h>

typedef struct master_s master_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfFloatRect GlobalB;
    sfSprite *sprite;
    sfTexture *txtbase;
    int hov;
    void (*callback)(master_t *master);
    struct button_s *next;
} button_t;

typedef struct buttonptr_s {
    button_t *first;
} buttonptr_t;

typedef struct player_s {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;     //      4
    int facing;         // 3          1
} player_t;             //      2

typedef struct txtbox_s {
    sfSprite *sprite;
    sfSprite *arrow;
    sfText *text;
    char *string;
    int status;     // 0 : no more text     1 : more text to be displayed
    int disp;
} txtbox_t;

typedef struct keyboard_s {
    int Z;
    int Q;
    int S;
    int D;
    int E;
    int I;
    int Mouse;
} keyboard_t;


typedef struct game_s {
    sfSprite *map;
    txtbox_t *txtbox;
    player_t *player;
    keyboard_t *key;
    char *board;
} game_t;

typedef struct menu_s {
    buttonptr_t *buttons;
    sfSprite *background;
    sfSprite *mouse;
} menu_t;

struct master_s {
    sfRenderWindow *window;
    menu_t *menu;
    game_t *game;
    int mouse;
    int state;
};


#endif /* !STRUCT_H_ */
