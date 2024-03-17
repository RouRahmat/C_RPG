/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** txtbox
*/

#include "include.h"

void txtbox_settext(txtbox_t *txtbox, int pos, char *str)
{
    int lenght = my_strlen(str) - pos;
    int arrow = 0;
    int i = 0;
    char line1[145];

    txtbox->status = 0;
    if (lenght > 140) {
        txtbox->status = 1;
        arrow = 4;
    }
    for (; i != lenght && i != 142 - arrow; i++, pos++) {
        if (i == 46 || i == 93) {
            line1[i] = '\n';
            i++;
        }
        line1[i] = str[pos];
    }
    line1[i] = '\0';
    sfText_setString(txtbox->text, line1);
}

