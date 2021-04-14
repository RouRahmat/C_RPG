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
    master->game = setgame();
    master->load = setload();
    master->state = 0;
    master->mouse = 0;
}

buttonptr_t *setbuttons_load(void)
{
    buttonptr_t *buttons = malloc(sizeof(buttonptr_t));
    float values[4] = {430, 150, 420, 100};

    buttons->first = NULL;
    init_button(buttons, values, quit, "asset/menu/loadbutton.png");
    values[0] = 430;
    values[1] = 320;
    values[2] = 420;
    values[3] = 100;
    init_button(buttons, values, quit, "asset/menu/loadbutton.png");
    values[0] = 430;
    values[1] = 485;
    values[2] = 420;
    values[3] = 100;
    init_button(buttons, values, quit, "asset/menu/loadbutton.png");
    return (buttons);
}

loadm_t *setload(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    sfTexture *bg;
    sfTexture *mse;

    bg = sfTexture_createFromFile("asset/menu/loadscreen.png", NULL);
    menu->buttons = setbuttons_load();
    menu->background = sfSprite_create();
    sfSprite_setTexture(menu->background, bg, sfFalse);
    return (menu);
}

void updateload(sfRenderWindow *window, loadm_t *load)
{
    sfRenderWindow_drawSprite(window, load->background, sfFalse);
    draw_buttons(load->buttons, window);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfTransparent);
}

void loadmenu(master_t *master)
{
    updateload(master->window, master->load);
    check_click(master, master->load->buttons);
}