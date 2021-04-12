/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** display string len
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (*str != '\0')
    {
        i++;
        *str++;
    }
    return (i);
}