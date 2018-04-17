/*
** EPITECH PROJECT, 2018
** ia_play.c
** File description:
** function play IA
*/

#include "matchstick.h"

int *create_result_array(mt_t *file)
{
	int *new = malloc(sizeof(int) * file->ligne_max);

	for (int i = 0; i < file->ligne_max; i++)
		new[i] = (file->nb[i] - file->nb_off[i]);
	return (new);
}

static int check_suggested_move(mt_t *file, int *nim_somme, int *counter)
{
	int count = file->nb[*counter] - file->nb_off[*counter];

	for (int i = 0; i < file->ligne_max; i++) {
		if (file->nb[i] - file->nb_off[i] > 1)
			return (1);
	}
	if (*nim_somme != 1)
		if (count == 0) {
			*nim_somme -= 1;
			file->nb_off[*counter] -= 1;
			return (0);
		}
	if (*nim_somme < file->nb_m)
		if (count == 1) {
			*nim_somme += 1;
			file->nb_off[*counter] += 1;
		}
	return (0);
}

static int somme_no_null(mt_t *file)
{
	int *save = create_result_array(file);
	int i = 0;
	int j = 0;

	for (; i < file->ligne_max; i++) {
		j = check_nombre(save, i, file->nb_m, file->ligne_max);
		free(save);
		save = create_result_array(file);
		if (j != 0)
			break;
	}
	if (j == 0) {
		random_play(file);
		return (0);
	}
	file->nb_off[i] += j;
	check_suggested_move(file, &j, &i);
	my_printf("AI removed %d match(es) from line %d\n",
		j, i + 1);
	return (0);
}

int turn_ia(mt_t *file)
{
	int nim_somme = init_ia(file);

	my_printf("\nAI's turn...\n");
	if (nim_somme != 0)
		somme_no_null(file);
	else
		random_play(file);
	return (0);
}
