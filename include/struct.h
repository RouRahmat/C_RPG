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
    sfSprite *s_inter;
    sfIntRect rect;
    sfVector2f pos;
    char hitbox[5];
    int facing;
    int att_dir;
} player_t;

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


typedef struct menu_s {
    buttonptr_t *buttons;
    sfSprite *background;
    sfSprite *mouse;
} menu_t;

typedef struct loadm_s {
    buttonptr_t *buttons;
    sfSprite *background;
} loadm_t;

typedef struct map_s {
    sfVector2f m_pos;
    sfVector2f p_pos;
    char *collisionpath;
    int loca;
    struct map_s *next
}map_t;

typedef struct maps_s {
    map_t *first;
}maps_t;

typedef struct game_s {
    sfSprite *map;
    sfSprite *fg_map;
    txtbox_t *txtbox;
    player_t *player;
    keyboard_t *key;
    maps_t *maps;
    char *board;
    int loca;
} game_t;

struct master_s {
    sfRenderWindow *window;
    menu_t *menu;
    game_t *game;
    loadm_t *load;
    int mouse;
    int state;
};


#endif /* !STRUCT_H_ */
