/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** run bonus
*/

#include "bonus.h"

void display_title(void)
{
	my_putstr("\n\n\n");
	my_putstr("M   M  AA  TTTTTT  CCC H  H  SSS  TTTTTT III  CCC K  K\n");
	my_putstr("MM MM A  A   TT   C    H  H S       TT    I  C    K K\n");
	my_putstr("M M M AAAA   TT   C    HHHH  SSS    TT    I  C    KK\n");
	my_putstr("M   M A  A   TT   C    H  H     S   TT    I  C    K K\n");
	my_putstr("M   M A  A   TT    CCC H  H SSSS    TT   III  CCC K  K\n");
}

void run_bonus(int ligne_max, int nb_m)
{
	char *s;
	mt_t *map = init_matchstick(ligne_max, nb_m);

	display_title();
	my_putstr("\n\nWelcome to the game\nPlease choose your mode\n\n");
	my_putstr("1. Player versus IA\n");
	my_putstr("2. players vs players\n\n");
	for (int i = 0; i < 1; i++) {
		s = get_next_line(0);
		if (my_getnbr(s) == 1)
			select_ia(map);
		else if (my_getnbr(s) == 2)
			select_player(map);
		else {
			my_putstr("\nPlease choose betwenn 1 or 2\n");
			i--;
		}
	}
}
