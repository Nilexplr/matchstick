/*
** EPITECH PROJECT, 2017
** my_strlowcase
** File description:
** low case
*/

#include "my.h"

char *my_strlowcase(char *str)
{
	char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 0;

	dest = my_strcpy(dest, str);
	while (dest[i] != '\0') {
		if (dest[i] <= 'Z' && dest[i] >= 'A')
			dest[i] = dest[i] + 32;
		i++;
	}
	return (dest);
}
