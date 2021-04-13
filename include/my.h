/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** get all fnc
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str);

int my_strlen(char const *str);

int my_strcmp(char const *stra, char const *strb, int n);

char *my_strcpy(char *dest, char const *src);

int my_char_isnum(char c);

int my_rand(int min, int max);

int my_put_nbr(int nbr);

int do_op(int nb1, int nb2, char operator);

int is_num(char c);

int my_atoi(char *str);

int my_compute_power_it(int nb, int p);

char *my_strclean(char *str);

int my_printf(const char *format, ...);

char **my_irarrcpy(char **dest, char const **src);

char *my_strcat(char *stra, char *strb);