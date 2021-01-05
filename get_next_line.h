/*
** EPITECH PROJECT, 2019
** GNL
** File description:
** get_next_line.h
*/

#ifndef READ_SIZE
#define READ_SIZE (1)

char *get_next_line(int);
char *case_of_buffer_empty(int, char *, char *, int);
int check_the_buffer(char *);
char *case_of_buffer_full(char *, char *, int);
char *my_strcat(char *, char *);

#endif