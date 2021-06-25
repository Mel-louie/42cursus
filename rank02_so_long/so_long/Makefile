# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 17:31:08 by user42            #+#    #+#              #
#    Updated: 2021/06/25 15:53:14 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS	= srcs/main.c \
			srcs/checks.c \
			srcs/draw_n_update.c \
			srcs/events.c \
			srcs/exits.c \
			srcs/get_data.c \
			srcs/map.c \
			srcs/screen.c \
			srcs/utils.c

OBJS	= $(SRCS:%.c=%.o)

# compiler
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

MLXFLAGS = -L./libs/mlx -lm -lmlx -lbsd -lX11 -lXext #linux 
MLX = libmlx.a
LIBFT = libft.a
INCDIR	= ./includes/

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libs/libft
	@make -C ./libs/mlx
	@cp ./libs/mlx/$(MLX) ./
	@cp ./libs/libft/$(LIBFT) ./
	@$(CC) $(OBJS)  $(LIBFT) $(CFLAGS) $(MLXFLAGS) -I $(INCDIR) -o $(NAME)
	@echo "\n\033[1;32mCompilation OK\n\033[0m"

clean :
	@echo "\033[0;36mCleaning..."
	@cd ./libs/libft; make clean
	@cd ./libs/mlx; make clean
	@rm -f $(OBJS)
	@echo "\033[1;36m\nCleaning done\n\033[0m"

fclean :
	@echo "\033[0;36mFcleanig, remove all...\n"
	@cd ./libs/libft; make fclean
	@cd ./libs/mlx; make clean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@echo "\033[1;36m\n\nCleaning done\n\033[0m"

norminette :
	@echo "\033[1;37m"
	@norminette --version
	@echo "\nNorming...\033[0m\n"
	@echo "SRCS:"
	@norminette ./srcs/*.c
	@echo "\nINCLUDES:"
	@norminette ./includes/*.h
	@echo "\nLIBFT:"
	@norminette ./libs/libft/includes/*.h ./libs/libft/srcs/*.c

re : fclean all

.PHONY: all clean fclean re