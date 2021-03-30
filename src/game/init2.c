/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** init2
*/

#include "include.h"


void initmaster(master_t *master)
{
    master->window = init_window();
    master->menu = setmenu();
    master->state = 0;
    master->mouse = 0;
}