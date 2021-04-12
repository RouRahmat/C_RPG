/*
** EPITECH PROJECT, 2021
** save.c
** File description:
** save
*/

#include "include.h"

void play_save(master_t *master)
{
    int fd = open("whattosave.data", O_CREAT | O_WRONLY,
    S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);
    if (fd == -1)
        return;
    write(fd, master, sizeof(master_t));
    close(fd);
}