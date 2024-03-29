# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 17:31:08 by user42            #+#    #+#              #
#    Updated: 2021/07/01 03:22:37 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS	= srcs/so_long.c \
			srcs/checks.c \
			srcs/collectibles.c \
			srcs/draw_n_update.c \
			srcs/ends.c \
			srcs/events.c \
			srcs/exits.c \
			srcs/frees.c \
			srcs/get_data.c \
			srcs/map.c \
			srcs/player.c \
			srcs/screen.c \
			srcs/utils.c

SRCS_BONUS	= bonus/srcs_bonus/so_long_bonus.c \
			bonus/srcs_bonus/checks_bonus.c \
			bonus/srcs_bonus/collectibles_bonus.c \
			bonus/srcs_bonus/draw_n_update_bonus.c \
			bonus/srcs_bonus/ends_bonus.c \
			bonus/srcs_bonus/enemies_bonus.c \
			bonus/srcs_bonus/events_bonus.c \
			bonus/srcs_bonus/exits_bonus.c \
			bonus/srcs_bonus/frees_bonus.c \
			bonus/srcs_bonus/get_data_bonus.c \
			bonus/srcs_bonus/map_bonus.c \
			bonus/srcs_bonus/player_bonus.c \
			bonus/srcs_bonus/screen_bonus.c \
			bonus/srcs_bonus/utils_bonus.c

OBJS	= $(SRCS:%.c=%.o)

OBJS_BONUS	= $(SRCS_BONUS:%.c=%.o)

# compiler
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -O3 -g3 #-fsanitize=address

MLXFLAGS = -L./libs/mlx -lm -lmlx -lbsd -lX11 -lXext #linux 
MLX = libmlx.a
LIBFT = libft.a
INCDIR	= ./includes/
INCDIR_BONUS = ./bonus/includes_bonus/

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
	@rm -f $(OBJS_BONUS)
	@echo "\033[1;36m\nCleaning done\n\033[0m"

fclean :
	@echo "\033[0;36mFcleanig, remove all...\n"
	@cd ./libs/libft; make fclean
	@cd ./libs/mlx; make clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
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

normibonus :
	@echo "\033[1;37m"
	@norminette --version
	@echo "\nNorming...\033[0m\n"
	@echo "SRCS_BONUS:"
	@norminette ./bonus/srcs_bonus/*.c
	@echo "\nINCLUDES_BONUS:"
	@norminette ./bonus/includes_bonus/*.h

bonus : $(OBJS_BONUS)
	@make -C ./libs/libft
	@make -C ./libs/mlx
	@cp ./libs/mlx/$(MLX) ./
	@cp ./libs/libft/$(LIBFT) ./
	@$(CC) $(OBJS_BONUS) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -I $(INCDIR_BONUS) -o $(NAME)
	@echo "\n\033[1;32mCompilation OK\n\033[0m"

re : fclean all

.PHONY: all clean fclean re