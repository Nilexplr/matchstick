/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game loop function
*/

#include "matchstick.h"

mt_t *init_matchstick(int ligne_max, int nb_m)
{
	mt_t *new = malloc(sizeof(mt_t));

	new->ligne_max = ligne_max;
	new->nb_m = nb_m;
	new->nb = init_nb(ligne_max);
	new->nb_off = init_nboff(ligne_max);
	return (new);
}

static int check_error(mt_t *list, int i)
{
	while ((i = updated_board_game(list)) != 0)
		if (i == 84)
			return (84);
	return (0);
}

static void display_ia_turn(mt_t *mtchstk)
{
	turn_ia(mtchstk);
	print_game_board(mtchstk);
	if (!finish_loop(mtchstk)) {
		my_putstr("I lost... snif... but I'll ");
		my_putstr("get you next time!!\n");
	}
}

int run_game(int ligne_max, int nb_m)
{
	mt_t *mtchstk = init_matchstick(ligne_max, nb_m);
	int i;

	print_game_board(mtchstk);
	while (finish_loop(mtchstk)) {
		my_putstr("\nYour turn:\n");
		if ((i = check_error(mtchstk, i)) == 84)
			return (84);
		print_game_board(mtchstk);
		if (!finish_loop(mtchstk)) {
			my_putstr("You lost, too bad...\n");
			return (2);
		}
		display_ia_turn(mtchstk);
		if (!finish_loop(mtchstk)) {
			return (1);
		}
	}
	return (0);
}
