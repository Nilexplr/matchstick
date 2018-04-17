##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## lib
##

CC	=	ar rc

RM	=	rm -f

NAME	=	libmy.a

SRC	=	my_putchar.c		\
		my_isneg.c		\
		my_put_nbr.c		\
		my_swap.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_getnbr.c		\
		my_compute_power_rec.c	\
		my_is_prime.c		\
		my_find_prime_sup.c	\
		my_strdup.c		\
		my_strcpy.c		\
		my_strncpy.c		\
		my_revstr.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_strlowcase.c		\
		my_str_isalpha.c	\
		my_str_isnum.c		\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_str_isprintable.c	\
		my_showstr.c		\
		my_compute_square_root.c\
		my_strdup.c		\
		my_strcat.c		\
		disp_stdarg.c		\
		my_putnbr_base.c	\
		disp_basearg.c		\
		my_putunsignedint.c	\
		disp_ptrarg.c		\
		my_printf.c	\
		my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	= 	-Iinclude -Wall -Wextra -W

all:	comp clean

comp:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
