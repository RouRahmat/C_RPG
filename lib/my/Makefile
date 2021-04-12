##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compil
##

SRC	=	my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_strlen.c\
		my_isnum.c\
		my_itoa.c\
		my_atoi.c\
		my_getnbr.c\
		my_rand.c\
		my_strcmp.c\
		my_strcpy.c\
		my_compute_power_it.c\
		do_op.c\
		my_strclean.c\
		my_printf.c\
		my_strarrcpy.c\
		my_strcat.c\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		cp my.h ../../include
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		rm -f $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		rm -f ../../include/my.h

re:     fclean all
