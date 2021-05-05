/*
** EPITECH PROJECT, 2020
** My_put_nbr.c
** File description:
** print a number
*/

#include "my.h"

int    my_put_nbr(int nb)
{
    int    temp;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            temp = (nb % 10);
            my_put_nbr((nb - temp) / 10);
            my_putchar(temp + 48);
        }
        else
            my_putchar(nb % 10 + 48);
    }
}