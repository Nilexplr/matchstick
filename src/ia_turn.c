/*
** EPITECH PROJECT, 2018
** ia_turn.c
** File description:
** ia function
*/

#include "matchstick.h"

int init_ia(mt_t *file)
{
	int somme = (file->nb[0] - file->nb_off[0]);
	int nbr;

	for (int i = 1; i < file->ligne_max; i++) {
		nbr = (file->nb[i] - file->nb_off[i]);
		somme ^= nbr;
	}
	return (somme);
}

int nim_xor(int *nbr, int counter)
{
	int somme = nbr[0];

	for (int i = 1; i < counter; i++)
		somme ^= nbr[i];
	return (somme);
}

int check_nombre(int *nbr, int i, int counter, int ligne_max)
{
	int save = nbr[i];

	for (int j = 1; j <= counter; j++) {
		nbr[i] = save - j;
		if (nbr[i] < 0)
			return (0);
		if (nim_xor(nbr, ligne_max) == 0)
			return (j);
	}
	return (0);
}
