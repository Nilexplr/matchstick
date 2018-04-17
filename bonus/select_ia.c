/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** select_ia.c
*/

#include "bonus.h"

void run_easy(mt_t *mtchstk)
{
	print_game_board(mtchstk);
	while (finish_loop(mtchstk)) {
		my_putstr("\nYour turn:\n");
		while ((updated_board_game(mtchstk)) != 0);
		print_game_board(mtchstk);
		if (!finish_loop(mtchstk)) {
			my_putstr("You lost, too bad...\n");
			exit(2);
		}
		random_play(mtchstk);
		print_game_board(mtchstk);
		if (!finish_loop(mtchstk)) {
			my_putstr("I lost... snif... but I'll ");
			my_putstr("get you next time!!\n");
			exit(1);
		}
	}
}

void run_medium(mt_t *mtchstk)
{
	int i = 0;

	print_game_board(mtchstk);
	while (finish_loop(mtchstk)) {
		my_putstr("\nYour turn:\n");
		while ((updated_board_game(mtchstk)) != 0);
		print_game_board(mtchstk);
		if (!finish_loop(mtchstk)) {
			my_putstr("You lost, too bad...\n");
			exit(2);
		}
		(i % 2 == 1) ? random_play(mtchstk) : turn_ia(mtchstk);
		print_game_board(mtchstk);
		if (!finish_loop(mtchstk)) {
			my_putstr("I lost... snif...\n");
			exit(1);
		}
		i++;
	}
}

void select_ia(mt_t *map)
{
	char *s;

	my_putstr("\n\n You can chose between 3 differents levels\n");
	my_putstr("1. Easy\n2. Medium\n3. Hard\n");
	for (int i = 0; i < 1; i++) {
		s = get_next_line(0);
		if (my_getnbr(s) == 1)
			run_easy(map);
		else if (my_getnbr(s) == 2)
			run_medium(map);
		else if (my_getnbr(s) == 3)
			run_game(map->ligne_max, map->nb_m);
		else {
			my_putstr("\nPlease choose betwenn 1 and 3\n");
			i--;
		}
	}
}
