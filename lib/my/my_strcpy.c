/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** function that copies a string into anthoer
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	if (dest == NULL)
		dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
