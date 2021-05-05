/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-romain.leemans
** File description:
** map
*/

#include "include.h"

void get_map(game_t *game, char *path)
{
    struct stat sb;
    stat(path, &sb);
    int BUFF_SIZE = sb.st_size;
    char buff[BUFF_SIZE];
    int offset = 0;
    int len;
    int file = open(path, O_RDONLY);

    game->board = malloc(BUFF_SIZE);
    while ((len = read(file, buff + offset , BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[BUFF_SIZE] = '\0';
    strcpy(game->board, buff);
}