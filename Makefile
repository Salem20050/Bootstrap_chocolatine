##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	main.c				\
		display.c			\
		my_strtok.c			\
		take_com.c			\
		my_strdup.c			\
		my_strcmp.c			\
		my_strncmp.c		\
		my_strlen.c			\
		triple.c			\
		cd.c				\
		getenv.c			\
		env.c				\
		my_putstr.c			\
		setenv.c			\
		my_strcat.c			\
		my_strcpy.c			\
		my_execvp.c			\
		divers.c			\
		search.c			\
		list.c				\
		clean_str.c			\
		cd_secour.c			\
		handling.c			\
		erno.c				\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	clean

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc  $(SRC) -o mysh
clean:	$(NAME)
	rm -f $(OBJ) $(NAME)
fclean: clean
	rm -f $(NAME)
re:	fclean all

tests_run: re