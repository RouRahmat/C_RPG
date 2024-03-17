/*
** EPITECH PROJECT, 2020
** my_strclean.c
** File description:
** remove space in a str
*/

#include "my.h"

char *my_strclean(char *str)
{
    int l = 1;
    int i = 0;
    char *clean_str;
    while (str[i] != '\0'){
        if (str[i] != ' ')
            l++;
        i++;
    }
    clean_str = malloc(sizeof(char)*l);
    i = 0;
    l = 0;
    while (str[i] != '\0'){
        if (str[i] != ' '){
            clean_str[l] = str[i];
            l++;
        }
        i++;
    }
    clean_str[l] = '\0';
    return (clean_str);
}
