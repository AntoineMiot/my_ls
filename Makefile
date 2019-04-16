##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC	=	my_ls.c	\
		my_ls_two.c	\
		no_arg.c	\
		no_arg_file.c	\
		arg_r.c	\
		arg_R.c	\
		arg_R_two.c	\
		arg_d.c	\
		arg_l.c	\
		arg_l_two.c	\
		arg_l_three.c	\
		arg_lrr.c	\
		arg_lrr_two.c	\
		arg_t.c	\
		arg_t_two.c	\
		arg_t_file.c	\
		arg_t_file_two.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -I./include
	rm *.o

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.o

fclean:	clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all
