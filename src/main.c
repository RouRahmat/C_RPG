/*
** EPITECH PROJECT, 2021
** BasicRepo
** File description:
** main
*/

#include "include.h"
#include <string.h>

typedef void(*fnc)(master_t*);


int main(int ac, char **av)
{
    sfClock * clock = sfClock_create();
    sfTime time;
    sfEvent event;
    master_t *master = malloc(sizeof(master_t));
    fnc func[5] = {menu, game, loadmenu};

    initmaster(master);
    while (sfRenderWindow_isOpen(master->window)) {
        while (sfRenderWindow_pollEvent(master->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(master->window);
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 16666) {
            sfClock_restart(clock);
            func[master->state](master);
        }
    }
    return (0);
}