##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile basic
##

NAME =	my_rpg

SRC=$(shell find src/. -name '*.c')

all:		$(NAME)

$(NAME):
		make -C ./lib/my/
		gcc -w $(SRC) -o $(NAME) -Llib -lmy -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -ggdb -lcsfml-audio -Iinclude -lraylib

clean:
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re:	fclean all