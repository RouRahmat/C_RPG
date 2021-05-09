/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** keys
*/

#include "include.h"

void defkey(keyboard_t *key)
{
    key->Z = 0;
    key->Q = 0;
    key->S = 0;
    key->D = 0;
    key->I = 0;
}

int igcheck_key_state(keyboard_t *key)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && key->E == 0){
        key->E = 1;
        return (1);
    } else if (!sfKeyboard_isKeyPressed(sfKeyE) && key->E == 1){
        key->E = 0;
        return (0);
    } else {
        return (0);
    }
}

void check_keys(master_t *master)
{
    keyboard_t *key = master->game->key;
    defkey(key);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && key->Z == 0)
        key->Z = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && key->Q == 0)
        key->Q = 1;
    if (sfKeyboard_isKeyPressed(sfKeyS) && key->S == 0)
        key->S = 1;
    if (sfKeyboard_isKeyPressed(sfKeyD) && key->D == 0)
        key->D = 1;
    if (sfKeyboard_isKeyPressed(sfKeyI) && key->I == 0)
        key->I = 1;
    key->Mouse = 0;
    /* if (igcheck_mouse_state(key) == 1)
        attack(master); */
}