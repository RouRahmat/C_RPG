/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** mouse
*/

#include "include.h"

int check_mouse_state(master_t *master)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && master->mouse == 0){
        master->mouse = 1;
        return (0);
    } else if (!sfMouse_isButtonPressed(sfMouseLeft) && master->mouse == 1){
        master->mouse = 0;
        return (1);
    } else {
        return (0);
    }
}