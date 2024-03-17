/*
** EPITECH PROJECT, 2020
** my_strarrcpy
** File description:
** copy an array of str into another
*/

#include "my.h"

char **my_iarrcpy(char **dest, char const **src)
{
    int k = 0;
    for (int i = 1; src[i] != NULL; i++, k++)
        for (int j = 0; src[i][j] != '\0'; j++)
            dest[k][j] = src[i][j];
    return (dest);
}