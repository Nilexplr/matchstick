/*
** EPITECH PROJECT, 2018
** init_nb.c
** File description:
** nb stick functions
*/

#include "matchstick.h"

int *init_nb(int ligne_max)
{
	int *nb = malloc(sizeof(int) * ligne_max);
	int nb_s = 1;

	for (int i = 0; i < ligne_max; i++) {
		nb[i] = nb_s;
		nb_s += 2;
	}
	return (nb);
}

int finish_loop(mt_t *list)
{
	for (int i = 0; i < list->ligne_max; i++)
		if (list->nb[i] - list->nb_off[i] != 0)
			return (1);
	return (0);
}

int *init_nboff(int ligne_max)
{
	int *nb_off = malloc(sizeof(int) * ligne_max);

	for (int i = 0; i < ligne_max; i++)
		nb_off[i] = 0;
	return (nb_off);
}
