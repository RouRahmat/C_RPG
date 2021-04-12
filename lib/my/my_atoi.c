/*
** EPITECH PROJECT, 2021
** bu B-MUL-200-LIL-2-1-mydefender-romain.leemans
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int val = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        }
        else
            return (val);
    str++;
    }
    return (val);
}