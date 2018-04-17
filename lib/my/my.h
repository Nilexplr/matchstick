/*
** EPITECH PROJECT, 2017
** ohhéé
** File description:
** hééé
*/

#ifndef MY_H
#define MY_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root (int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime( int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char *);
int sum_stdarg(int i, int nb, ...);
void disp_c(va_list ap);
void disp_s(va_list ap);
void disp_i(va_list ap);
void disp_mod(va_list ap);
int my_putnbr_base(unsigned int nb, char *base);
void disp_o(va_list ap);
void disp_x(va_list ap);
void disp_x_m(va_list ap);
void disp_u(va_list ap);
void disp_b(va_list ap);
void disp_s_m(va_list ap);
void disp_p(va_list ap);
int my_put_unsigned(unsigned int nb);
int octal_base(unsigned int nb);
int zero_case(char *s, int i);
void display_s(char s);
int display_l(char *s, int i);
int my_printf(char *s, ...);

#endif /* MY_H_ */
