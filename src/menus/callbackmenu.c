/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** callbackmenu
*/

#include "include.h"

void quit(master_t *master)
{
    sfRenderWindow_close(master->window);
}

void play(master_t *master)
{
    master->state = 1;
}