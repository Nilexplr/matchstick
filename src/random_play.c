/*
** EPITECH PROJECT, 2018
** random_play.c
** File description:
** random play function
*/

#include <time.h>
#include "matchstick.h"

int find_nb_line(mt_t *file)
{
	int nb_line = 0;

	for (int i = 0; i < file->ligne_max; i++) {
		if (file->nb[i] - file->nb_off[i] > 0)
			nb_line++;
	}
	return (nb_line);
}

int find_y(mt_t *file, int nb)
{
	for (int i = 0; i < file->ligne_max; i++) {
		if (file->nb[i] - file->nb_off[i] > 0)
			nb--;
		if (nb == 0)
			return (i);
	}
	return (0);
}

int random_play(mt_t *file)
{
	int random1;
	int random2;
	int nb_line = find_nb_line(file);
	int counter;

	srand(time(NULL));
	random1 = find_y(file, rand() % nb_line + 1);
	counter = file->nb[random1] - file->nb_off[random1];
	if (counter < file->nb_m)
		random2 = rand() % (counter) + 1;
	else
		random2 = rand() % file->nb_m + 1;
	file->nb_off[random1] += random2;
	my_printf("AI removed %d match(es) from line %d\n",
		random2, random1 + 1);
	return (0);
}
