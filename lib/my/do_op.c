/*
** EPITECH PROJECT, 2020
** do_op.c
** File description:
** make op from string
*/

#include "my.h"

int do_op(int nb1, int nb2, char operator)
{
    int result = 0;
    if (operator == '+'){
        result = nb1+nb2;
    } else if (operator == '-'){
        result = nb1-nb2;
    }
    if (nb1 != 0 && nb2 != 0 && operator == '/'){
        result = nb1/nb2;
    } else if (operator == '*'){
        result = nb1 * nb2;
    }
    if (nb1 != 0 && nb2 != 0 && operator == '%'){
        result = nb1%nb2;
    }
    return (result);
}
