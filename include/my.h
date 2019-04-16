/*
** EPITECH PROJECT, 2018
** include functions
** File description:
** include functions
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int check_number(char *str);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int nb_special(long nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
int low(char c);
int up(char c);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_str_isalpha(char *str);
char *my_str_islower(char *str);
char *my_str_isnum(char *str);
char *my_str_isprintable(char *str);
char *my_str_isupper(char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void *infin_add(char *nb1, char *nb2);
int my_str_taller(char const *s1, char const *s2);
char *big_nb(char *nb1, char *nb2);
char *small_nb(char *nb1, char *nb2);
int my_str_is_equal(char *str1, char *str2);
void my_put_infinadd(int ret, char *nb, int type);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
void no_arg(void);
void just_file(int ac, char **av);
int distrib_two(int ac, char **av, int option);
void just_file_solo(char *filepath);
int no_arg_disp_space(int z, int i);
void no_arg_color_disp(char *str, int type);
void arg_tt(int ac, char **av);
void arg_d(int ac, char **av);
void arg_rr(int ac, char **av);
void arg_l(int ac, char **av);
void arg_r(int ac, char **av);
void disp_arg_r(char **tbl, int z);
char **sort_file_time(char **tbl_sort, char *str);
char **tab_int_time_two(char **tbl, int z);
void swap_elem(char **tbl, long int *tbl_int, int index1, int index2);
void sort_time_with_arg_file(char *filepath);
void tab_int_time(char **tbl, int z);
void sort_time_with_one_file(char *filepath);
void arg_rrl(int ac, char **av);
int check_arg_command(int ac, char **av);
int disp_arg_rrl(char *str, int z, char *filepath, int i);
void file_arg_rrl_putstr(char *filepath);
void permission(char *str, char *name, int type);
void folders(char *str, int type);
void time_modif(char *str);
void nlink(char *str);
void other(char *str);
void group(char *str);
void utilisa(char *str);
void file_arg_rr(char *filepath);
void file_arg_rr_two(char *filepath);
void permission(char *str, char *name, int type);
void file_arg_rr_scnd(char *filepath, int z, int i);
int disp_arg_rr_two(char *str, int z, char *filepath, int i);
void recursiv_two(char **tab);
void recursiv(char **tab);
void sort_tbl_by_time(char **tbl, long int *tbl_int, int z);
void tab_int_time_file(char **tbl, int z, char *filepath);
void check_slash(char **av, int i);
void array_file(char *filepath);
void total_block(char *filepath);