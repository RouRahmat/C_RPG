/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare two string in ascii value
*/

#include "my.h"

int my_strcmp(char const *stra, char const *strb, int n)
{
    while (*stra != '\0' && *strb != '\0')
    {
        if (*stra < *strb){
            return (-1);
        } else if (*stra > *strb) {
            return (1);
        } else {
            *stra++;
            *strb++;
        }
    }
    return (0);
}
