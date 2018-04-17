##
## EPITECH PROJECT, 2017
## My_popup_2017
## File description:
## Makefile
##

SRC	=	./src/print_game_board.c	\
		./src/game_loop.c		\
		./src/init_nb.c			\
		./src/update_game.c		\
		./src/get_next_line.c		\
		./src/ia_turn.c			\
		./src/ia_play.c			\
		./src/random_play.c

UT_SRC	=	./tests/test_my_strlen.c		\
		./tests/test_count_char_line.c		\
		./tests/test_check_line.c		\
		./tests/test_get_next_line.c		\
		./tests/test_init_matchstick.c		\
		./tests/test_nim_xor.c			\
		./tests/test_init_ia.c			\
		./tests/test_check_nombre.c		\
		./tests/test_init_nb.c			\
		./tests/test_finish_loop.c		\
		./tests/test_init_nboff.c		\
		./tests/test_print_game_board.c		\
		./tests/test_random_play.c		\
		./tests/test_matches_error.c		\
		./tests/test_line_error.c		\
		./tests/test_turn_ia.c			\
		./tests/test_create_result_array.c	\
		./tests/test_run_game.c			\
		./tests/test_printf.c			\
		./tests/test_my_str_isnum.c		\
		./tests/test_my_putstr.c		\

OBJ	=	$(SRC:.c=.o)

MAIN	=	./src/main.c

LDFLAGS	=	-lcriterion -lgcov --coverage

CFLAGS	=	-I./include -W -Wall -Wextra -Werror -pedantic

NAME	=	matchstick

LIB_DIR	=	-L./lib/my/ -lmy

BONUS_SRC	=	./bonus/main_bonus.c	\
			./bonus/run_bonus.c	\
			./bonus/select_ia.c	\
			./bonus/select_player.c


all:		$(NAME)

$(NAME):	$(OBJ) $(MAIN:.c=.o)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(MAIN:.c=.o) $(LIB_DIR) $(CFLAGS)

tests_run:
		gcc -o units $(SRC) $(UT_SRC) $(CFLAGS) $(LDFLAGS) $(LIB_DIR)
		./units

show_coverage:
		gcc -o units $(SRC) $(UT_SRC) $(CFLAGS) $(LDFLAGS) $(LIB_DIR)
		./units
		lcov --directory ./ -c -o rapport.info
		genhtml -o ./report -t "code coverage report" rapport.info
		xdg-open ./report/index.html &>/dev/null

bonus:		$(BONUS_SRC:.c=.o) $(OBJ)
		make -C lib/my
		gcc -o Matchstick $(OBJ) $(BONUS_SRC:.c=.o) $(LIB_DIR) $(CFLAGS)
clean:
	rm -f $(OBJ) $(LIB_OBJ) $(MAIN:.c=.o) $(BONUS_SRC:.c=.o) *.gc*

fclean:	clean
	rm -f $(NAME) $(UT) units Matchstick
	rm -f rapport.info
	rm -rf report

re:	fclean all
