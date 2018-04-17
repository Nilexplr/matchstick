/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main matchstick
*/

#include "bonus.h"

void print_usage(void)
{
	my_putstr("USAGE:\t./Matchstick\t[number of lines]\t[number of stick");
	my_putstr(" maximum per turn]\n\nDESCRIPTION:\n\tMODE Player vs IA: ");
	my_putstr("The looser is the one who take the last matchstick\n\n\t");
	my_putstr("MODE player vs player: The winner is the one who take the");
	my_putstr(" last matchstick\n\n\n");
	my_putstr("{___     {__{__{__            {_\n");
	my_putstr("{_ {__   {__{__{__           {_ __\n");
	my_putstr("{__ {__  {__{__{__          {_  {__\n");
	my_putstr("{__  {__ {__{__{__         {__   {__\n");
	my_putstr("{__   {_ {__{__{__        {______ {__\n");
	my_putstr("{__    {_ __{__{__       {__       {__\n");
	my_putstr("{__      {__{__{________{__         {__\n");
}

int main(int ac, char **av)
{
	int ligne_max;
	int nb_m;

	if (ac != 3) {
		print_usage();
		return (0);
	}
	ligne_max = my_getnbr(av[1]);
	if (ligne_max < 2 || ligne_max > 99)
		return (84);
	nb_m = my_getnbr(av[2]);
	if (nb_m < 1)
		return (84);
	run_bonus(ligne_max, nb_m);
	return (0);
}
