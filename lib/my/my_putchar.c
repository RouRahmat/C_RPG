/*
** EPITECH PROJECT, 2020
** putchar.c
** File description:
** print a char
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
