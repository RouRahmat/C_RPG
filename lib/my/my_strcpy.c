/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string in another allocated string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0'){
        *dest = *src;
        *dest++;
        *src++;
    }
    *dest = '\0';
    return (dest);
}
