NAME = microshell
CC = clang
FLAGS = -Wall -Wextra -Werror

SRC = main.c
OBJ = $(SRC:.c=.o)


$(NAME):	$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

fclean:	clean
	rm $(NAME) || true

clean:
	rm $(OBJ) || true

re: fclean all
