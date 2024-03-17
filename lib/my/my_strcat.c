/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concatenates characters of the str in dest
*/

#include "my.h"

char *my_strcat(char *stra, char *strb)
{
    char *fusion = malloc(my_strlen(stra) + my_strlen(strb));
    int i = 0;

    for (int a = 0; stra[a]; a++, i++)
        fusion[i] = stra[a];
    for (int a = 0; stra[a]; a++, i++)
        fusion[i] = strb[a];
    fusion[i++] = '\0';
    return (fusion);
}
