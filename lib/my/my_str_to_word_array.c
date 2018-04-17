/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** take a string as param and convert it to tab **
*/

#include "my.h"

int my_wordlen(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0') {
		if (my_str_isnum(str) == 0 && my_str_isalpha(str) == 0)
			count++;
		i++;
	}
	return (count);
}

char **my_str_to_word_array(char *str)
{
	int j = 0;
	int i = 0;
	int k = 0;
	char **tab = malloc(sizeof(char*) * my_wordlen(str) + 1);

	while (str[i] != '\0') {
		tab[k] = malloc(sizeof(char*) * my_strlen(str));
		while (my_str_isnum(str) == 0 && my_str_isalpha(str) == 0)
			i++;
		j = 0;
		while (my_str_isnum(str) == 1 || my_str_isalpha(str) == 1) {
			tab[k][j] = str[i];
			i++;
			j++;
		}
		k++;
	}
	tab[k] = '\0';
	return (tab);
}
