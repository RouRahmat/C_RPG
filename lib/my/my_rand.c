/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_rand
*/

#include "my.h"

int my_rand(int min, int max)
{
    return (rand() % (max + 1 - min) + min);
}