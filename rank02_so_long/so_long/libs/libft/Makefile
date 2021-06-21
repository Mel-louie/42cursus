# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 15:17:57 by mdesfont          #+#    #+#              #
#    Updated: 2021/06/11 15:49:50 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################
#    COLORS    #
################

_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_VIOLET		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"

################
#    DETECT	   #
#	   OS      #
################

OS_NAME := $(shell uname -s | tr A-Z a-z)

SRC =	./srcs/ft_atoi.c \
		./srcs/ft_bzero.c \
		./srcs/ft_frees.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_puts.c \
		./srcs/ft_split.c \
		./srcs/ft_strs.c \
		./srcs/ft_strns.c \
		./srcs/ft_strjoinfree.c \
		./srcs/ft_swaps.c \
		./srcs/get_next_line.c

OBJ = $(SRC:.c=.o)

Ctab = -Wall -Wextra -Werror -g3 -fsanitize=address
NAME = libft.a

CC = gcc

.c.o::
		$(CC) $(Ctab) -c $< -o $(<:.c=.o)

$(NAME):: $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo $(_GREEN)"\nlibft.a created"$(_END)

all:		$(NAME)

clean:
	@echo $(_RED)"Cleaning in progress..."$(_END)
	@rm -f $(OBJ)
	@echo $(_GREEN)"Cleaning done!"$(_END)

fclean:	 clean
	@rm -f $(NAME)
	@echo $(_GREEN)"libft.a is delete"$(_END)

re:		fclean all

os:
	@echo $(_CYAN)"The OS is currently: "$(_END)$(_YELLOW)$(OS_NAME)$(_END)

.PHONY:		all clean fclean re
