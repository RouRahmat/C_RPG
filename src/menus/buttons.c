/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** buttons
*/

#include "include.h"

button_t *init_button(buttonptr_t *buttonptr, float values[4],
void (*f)(sfRenderWindow *), char *path)
{
    button_t *btn = malloc(sizeof(button_t));
    sfVector2f sfposition = {values[0], values[1]};
    sfVector2f sfsize = {values[2], values[3]};

    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(btn->rect, sfposition);
    sfRectangleShape_setSize(btn->rect, sfsize);
    btn->GlobalB = sfRectangleShape_getGlobalBounds(btn->rect);
    btn->txtbase = sfTexture_createFromFile(path, NULL);
    btn->hov = 0;
    btn->sprite = sfSprite_create();
    sfSprite_setTexture(btn->sprite, btn->txtbase, sfFalse);
    sfSprite_setPosition(btn->sprite, sfposition);
    btn->callback = f;
    btn->next = buttonptr->first;
    buttonptr->first = btn;
    return (btn);
}

void draw_buttons(buttonptr_t *buttonptr, sfRenderWindow *window)
{
    button_t *Node = buttonptr->first;
    sfIntRect rec = {0, 0, 423, 102};
    while (Node){
        rec.left = 423 * Node->hov;
        sfSprite_setTextureRect(Node->sprite, rec);
        sfRenderWindow_drawSprite(window, Node->sprite, NULL);
        Node = Node->next;
    }
}

buttonptr_t *setbuttons_menu(void)
{
    buttonptr_t *buttons = malloc(sizeof(buttonptr_t));
    float values[4] = {480, 200, 310, 100};

    buttons->first = NULL;
    init_button(buttons, values, play, "./asset/menu/new.png");
    values[0] = 480;
    values[1] = 500;
    values[2] = 310;
    values[3] = 100;
    init_button(buttons, values, quit, "./asset/menu/quit.png");
    values[0] = 480;
    values[1] = 350;
    values[2] = 310;
    values[3] = 100;
    init_button(buttons, values, load, "./asset/menu/load.png");
    return (buttons);
}