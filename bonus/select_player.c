/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** select_player.c
*/

#include "bonus.h"

char **select_name(int nb_player)
{
	char **tab = malloc(sizeof(char*) * nb_player);

	for (int i = 0; i < nb_player; i++) {
		my_printf("\nEnter the name of the player %d:\n", (i + 1));
		tab[i] = get_next_line(0);
	}
	tab[nb_player] = NULL;
	return (tab);
}

void loop_player(mt_t *mtchstk, char **tab, int nb_player)
{
	int i = 0;

	print_game_board(mtchstk);
	while (finish_loop(mtchstk)) {
		my_printf("\n%s's turn:\n", tab[i]);
		while ((updated_board_game(mtchstk)) != 0);
		print_game_board(mtchstk);
		if (!finish_loop(mtchstk))
			my_printf("! %s WIN !\n", tab[i]);
		i++;
		if (i == nb_player)
			i = 0;
	}
}

void select_player(mt_t *map)
{
	int nb_player;
	char *s;
	int i = 0;
	char **tab;

	my_putstr("\nHow many players want to play ?\n");
	while ((i == 0)) {
		s = get_next_line(0);
		if (!my_str_isnum(s))
			my_putstr("\nPlease, enter a positif number\n");
		else {
			nb_player = my_getnbr(s);
			i++;
		}
	}
	tab = select_name(nb_player);
	loop_player(map, tab, nb_player);
}
