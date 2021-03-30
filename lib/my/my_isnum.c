/*
** EPITECH PROJECT, 2020
** my_char_isnum.c
** File description:
** check if a char is num
*/

#include "my.h"

int my_isnum(char c)
{
    if (c < 58 && c > 47){
        return (1);
    } else {
        return (0);
    }
}
