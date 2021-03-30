/*
** EPITECH PROJECT, 2020
** My_getnbr.c
** File description:
** get nbr from a str
*/

#include "my.h"

int my_getnbr(char *str)
{
    int nbr = 0;
    int minus = 0;
    while (*str == '-'){
        *str++;
        minus++;
    }
    while (*str != '\0' && *str < 58 && *str > 47 ){
        nbr += *str - 48;
        nbr *= 10;
        *str++;
    }
    nbr /= 10;
    if (minus != 0)
        return (nbr * -1);
    else
        return (nbr);
}
