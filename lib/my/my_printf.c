/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf syscall
*/

#include "my.h"

int flags(char const * format, int var)
{
    char c;
    switch (*format) {
        case 'i':
            my_put_nbr(var);
            break;
        case 'd':
            my_put_nbr(var);
            break;
        case 'u':
            my_put_nbr((unsigned int) var);
        case 'c':
            c = var;
            my_putchar(c);
            break;
        default:
            my_putchar(*format);
            break;
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int temp;

    va_start(ap, format);

    for (; *format; *format++) {
        if (*format != '%')
            my_putchar(*format);
        else {
            *format++;
            if (*format == 's')
                my_putstr(va_arg(ap, char *));
            else
                flags(format, va_arg(ap, int));
            }
    }
}