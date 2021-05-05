/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** pow
*/

#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p<0 || nb<0)
        return (0);
    else if (p == 0)
        return (1);
    else
        for (p; p > 1; p--)
            result *= nb;
    return (result);
}
