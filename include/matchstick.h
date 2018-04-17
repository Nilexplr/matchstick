/*
** EPITECH PROJECT, 2018
** matchstick.h
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_
#include "my.h"
#include "get_next_line.h"
#include "stdbool.h"

typedef struct matchstick_s {
	int ligne_max;
	int nb_m;
	int *nb;
	int *nb_off;
}mt_t;

int print_game_board(mt_t *list);
int print_board(int nb, int ligne, int total, int nb_off);
int *init_nb(int ligne_max);
int run_game(int ligne_max, int nb_m);
int finish_loop(mt_t *list);
int *init_nboff(int ligne_max);
int updated_board_game(mt_t *list);
int turn_ia(mt_t *file);
int init_ia(mt_t *file);
int check_nombre(int *nbr, int i, int counter, int ligne_max);
int random_play(mt_t *file);
mt_t *init_matchstick(int ligne_max, int nb_m);
int nim_xor(int *nbr, int counter);
int find_y(mt_t *file, int nb);
int find_nb_line(mt_t *file);
int matches_error(char *s, mt_t *list, int line);
int line_error(char *s, mt_t *list);
int *create_result_array(mt_t *file);

#endif /* MATCHSTICK_H_ */
