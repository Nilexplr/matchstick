/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** macro get_next_line
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define READ_SIZE (1000)
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
