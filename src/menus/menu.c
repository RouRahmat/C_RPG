/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** menu
*/

#include "include.h"

menu_t *setmenu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    sfTexture *bg;
    sfTexture *mse;

    bg = sfTexture_createFromFile("asset/menu/titlescreen.png", NULL);
    menu->buttons = setbuttons_menu();
    menu->background = sfSprite_create();
    sfSprite_setTexture(menu->background, bg, sfFalse);
    return (menu);
}

void updatemenu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->background, sfFalse);
    draw_buttons(menu->buttons, window);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfTransparent);
}

void check_click(master_t *master, buttonptr_t *buttons)
{
    sfRenderWindow *window = master->window;
    sfVector2i mouse_p = sfMouse_getPosition(master->window);
    sfVector2f m_t = sfRenderWindow_mapPixelToCoords(window, mouse_p, NULL);
    button_t *Node = buttons->first;

    while (Node){
        if (sfFloatRect_contains(&Node->GlobalB, m_t.x, m_t.y)){
            if (check_mouse_state(master) == 1)
                Node->callback(master);
            Node->hov = 1;
        } else
            Node->hov = 0;
        Node = Node->next;
    }
}

int menu(master_t *master)
{
    updatemenu(master->window, master->menu);
    check_click(master, master->menu->buttons);
}