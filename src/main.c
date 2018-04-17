/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main matchstick
*/

#include "matchstick.h"

int main(int ac, char **av)
{
	int ligne_max;
	int nb_m;
	int i = 0;

	if (ac != 3)
		return (84);
	ligne_max = my_getnbr(av[1]);
	if (ligne_max < 2 || ligne_max > 99)
		return (84);
	nb_m = my_getnbr(av[2]);
	if (nb_m < 1)
		return (84);
	i = run_game(ligne_max, nb_m);
	if (i != 0 && i != 84)
		return (i);
	return (0);
}
