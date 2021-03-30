/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** get all fnc
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "my.h"
#include "struct.h"


//game.c
void quit(master_t *master);

void play(master_t *master);

void check_click(master_t *master, buttonptr_t *buttons);

menu_t *setmenu();

void updatemenu(sfRenderWindow *window, menu_t *menu);

//buttons.c

button_t *init_button(buttonptr_t *buttonptr, float values[4],
void (*f)(sfRenderWindow *), char *path);

void draw_buttons(buttonptr_t *buttonptr, sfRenderWindow *window);

buttonptr_t *setbuttons_menu(void);

//  - - - - - src/display - - - - -
//  display.c

void display (sfRenderWindow *window, master_t *master);

//  - - - - - src/ - - - - -

//  init.c
sfRenderWindow *init_window (void);

//  main.c
int main(int ac, char **av);

//No sort

int check_mouse_state(master_t *master);

void initmaster(master_t *master);

int menu(master_t *master);