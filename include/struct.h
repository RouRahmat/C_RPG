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

typedef struct menu_s {
    buttonptr_t *buttons;
    sfSprite *background;
} menu_t;

typedef struct loadm_s {
    buttonptr_t *buttons;
    sfSprite *background;
} loadm_t;

struct master_s {
    sfRenderWindow *window;
    menu_t *menu;
    loadm_t *load;
    int mouse;
    int state;
};


#endif /* !STRUCT_H_ */
