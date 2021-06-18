# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 11:01:29 by mdesfont          #+#    #+#              #
#    Updated: 2020/07/31 12:52:32 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRCS		= srcs/bmp.c \
				srcs/cub3d.c \
				srcs/parsing.c \
				srcs/events.c \
				srcs/moves.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/initialisation.c \
				srcs/clear.c \
				srcs/set_game.c \
				srcs/get_datas.c \
				srcs/sprite.c \
				srcs/sprite2.c \
				srcs/raycasting.c \
				srcs/raycasting2.c

OBJS	= $(SRCS:%.c=%.o)

# compiler
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g #-O3 #-fsanitize=address

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
	@echo "\n\033[0;32mCompilation OK"
	@echo "\033[0m"

clean :
	@echo "\033[0;36mCleaning..."
	@cd ./libs/libft; make clean
	@cd ./libs/mlx; make clean
	@rm -f $(OBJS)
	@echo "\033[0;36mCleaning done"
	@echo "\033[0m"

fclean :
	@echo "\033[0;36mFcleanig, remove all...\n"
	@cd ./libs/libft; make fclean
	@cd ./libs/mlx; make clean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@echo "\033[0;36m\n\nCleaning done"
	@echo "\033[0m"

normi :
	@echo "Norming..."
	norminette ./srcs/*.c ./includes/*.h

re : fclean all

.PHONY: all clean fclean re
