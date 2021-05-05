/*
** EPITECH PROJECT, 2020
** My_put_nbr.c
** File description:
** print a number
*/

#include "my.h"

char my_itoa(int nb, char *str)
{
    int len = 0;
    int tmp = nb;

    if (nb < 10) {
        str[0] = ' ';
        str[1] = 48 + nb;
        str[2] = 0;
    }
    else {
        while (tmp > 0) {
                tmp /= 10;
                len++;
            }
        str[len] = '\0';
        for (int i = 0; i != len; i++) {
            str[len - i - 1] = nb % 10  + '0';
            nb /= 10;
        }
    }
}