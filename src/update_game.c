/*
** EPITECH PROJECT, 2018
** update_game.c
** File description:
** update board game
*/

#include "matchstick.h"

int line_error(char *s, mt_t *list)
{
	if (!my_str_isnum(s)) {
		my_putstr("Error: invalid input (postive number expected)\n");
		return (1);
	}
	if (my_getnbr(s) < 1 || my_getnbr(s) > list->ligne_max) {
		my_putstr("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}

static void display_error(mt_t *list)
{
	my_putstr("Error: you cannot remove more than ");
	my_printf("%d matches per turn\n", list->nb_m);
}

int matches_error(char *s, mt_t *list, int line)
{
	int stick;

	if (!(my_str_isnum(s))) {
		my_putstr("Error: invalid input (postive number expected)\n");
		return (1);
	}
	stick = my_getnbr(s);
	if (my_getnbr(s) > list->nb_m) {
		display_error(list);
		return (1);
	}
	if (stick < 1) {
		my_putstr("Error: you have to remove at least one match\n");
		return (1);
	}
	if (stick > (list->nb[line - 1] - list->nb_off[line - 1])) {
		my_putstr("Error: not enough matches on this line\n");
		return (1);
	}
	return (0);
}

static void display_move(mt_t *list, int line, int nb, char *s)
{
	list->nb_off[line - 1] += nb;
	my_printf("Player removed %d match(es) from line %d\n", nb, line);
	free(s);
}

int updated_board_game(mt_t *list)
{
	int line;
	int nb;
	char *s;

	my_putstr("Line: ");
	if ((s = get_next_line(0)) != NULL)
		line = my_getnbr(s);
	else
		return (84);
	if (line_error(s, list))
		return (1);
	my_putstr("Matches: ");
	if ((s = get_next_line(0)) != NULL)
		nb = my_getnbr(s);
	else
		return (84);
	if (matches_error(s, list, line))
		return (1);
	display_move(list, line, nb, s);
	return (0);
}
