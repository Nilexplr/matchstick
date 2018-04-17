/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line function
*/

#include "get_next_line.h"

int count_char_line(char *s, int *cursor)
{
	int j = 0;

	for (int i = *cursor; s[i] == '\n'; i++)
		*cursor += 1;
	for (int i = *cursor; s[i] != '\n' && s[i] != '\0'; i++)
		j++;
	return (j);
}

int my_strlen(char const *str)
{
	int a = 0;

	while (str[a] != '\0') {
		a++;
	}
	return (a);
}

int check_line(char *s, int *cursor)
{
	for (int i = *cursor; s[i] != '\0'; i++) {
		if (s[i] == '\n') {
			(*cursor)++;
			return (1);
		}
	}
	return (0);
}

char *str_concate(char *src, char *dest, int size, int *cursor)
{
	char *new;
	int len = 0;
	int j = *cursor;

	if (dest == 0)
		new = malloc(sizeof(char) * count_char_line(src, cursor) + 1);
	else {
		len = my_strlen(dest);
		new = malloc(sizeof(char) * (len + *cursor));
		for (int i = 0; dest[i] != '\0'; i++)
			new[i] = dest[i];
	}
	for (; src[j] != '\n' && j < size; len++, j++)
		new[len] = src[j];
	new[len] = '\0';
	*cursor = j;
	return (new);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1];
	static int cursor = 0;
	static int size = 1;
	char *dest = NULL;
	int i = 0;
	int count = 0;

	while (i == 0 && size != 0) {
		if (buffer[cursor] == '\0') {
			size = read(fd, buffer, READ_SIZE);
			cursor = 0;
			buffer[size] = '\0';
		}
		if (size > 0) {
			dest = str_concate(buffer, dest, size, &cursor);
			count += size;
			i = check_line(buffer, &cursor);
		}
	}
	return (dest);
}
