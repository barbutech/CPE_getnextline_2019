/*
** EPITECH PROJECT, 2019
** GNL
** File description:
** get_next_line.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int size_dest = 0;
    int size_src = 0;
    char *tmp;

    for (; dest[size_dest] != '\0'; size_dest++);
    for (; src[size_src] != '\0'; size_src++);
    tmp = malloc(sizeof(char) * (size_dest + size_src + 1));
    if (tmp == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        tmp[i] = dest[i];
    for (int j = 0; src[j] != '\0'; i++, j++)
        tmp[i] = src[j];
    tmp[i] = '\0';
    return (tmp);
}

char *get_next_line(int fd)
{
    static char *buffer = "\0";
    static int count = 0;
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    char *ret = "\0";
    static int size = 0;
    if (fd == 0)
        if (size + 1 == count && buffer[count] == '\0')
            return (NULL);
    int nb = read(fd, tmp, READ_SIZE);
    tmp[nb] = '\0';

    if (nb == 0 && size + 1 == count)
        return (NULL);
    if (fd == -1 || nb == -1)
        return (NULL);
    buffer = my_strcat(buffer, tmp);
        size = count;
        for (; buffer[count] != '\n'
        && buffer[count] != '\0'; count++) {
            for (int size = count + nb; count < size - 1
            && buffer[count] != '\n' ; count++);
            if (buffer[count] == '\n')
                break;
            nb = read(fd, tmp, READ_SIZE);
            tmp[nb] = '\0';
            buffer = my_strcat(buffer, tmp);
        }
        ret = malloc(sizeof(char) * (count + 1));
        ret[count] = '\0';
        for (int copy = 0; size < count; copy++, size++) {
            ret[copy] = buffer[size];
        }
        count++;
        free(tmp);
        return (ret);
}