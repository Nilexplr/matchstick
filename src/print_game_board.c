/*
** EPITECH PROJECT, 2018
** print_game_board.c
** File description:
** print board functions
*/

#include "matchstick.h"

int print_board(int nb, int ligne, int total, int nb_off)
{
	my_putchar('*');
	for (int i = 0; i < total - ligne; i++)
		my_putchar(' ');
	for (int i = 0; i < nb - nb_off; i++)
		my_putchar('|');
	for (int i = 0; i < nb_off; i++)
		my_putchar(' ');
	for (int i = 0; i < total - ligne; i++)
		my_putchar(' ');
	my_putchar('*');
	my_putchar('\n');
	return (0);
}

int print_game_board(mt_t *list)
{
	for (int i = -1; i < list->ligne_max * 2; i++)
		my_putchar('*');
	my_putchar('\n');
	for (int i = 0; i < list->ligne_max; i++)
		print_board(list->nb[i], (i + 1),
			list->ligne_max, list->nb_off[i]);
	for (int i = -1; i < list->ligne_max * 2; i++)
		my_putchar('*');
	my_putchar('\n');
	return (0);
}
