# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 10:45:04 by mdesfont          #+#    #+#              #
#    Updated: 2020/09/22 12:27:06 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./srcs/ft_atoi.c \
		./srcs/ft_bzero.c \
		./srcs/ft_isalnum.c \
		./srcs/ft_isalpha.c \
		./srcs/ft_isascii.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_isprint.c \
		./srcs/ft_memccpy.c \
		./srcs/ft_memchr.c \
		./srcs/ft_memcmp.c \
		./srcs/ft_memcpy.c \
		./srcs/ft_memmove.c \
		./srcs/ft_memset.c \
		./srcs/ft_strchr.c \
		./srcs/ft_strdup.c \
		./srcs/ft_strndup.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strlcpy.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strcmp.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_strnstr.c \
		./srcs/ft_strrchr.c \
		./srcs/ft_substr.c \
		./srcs/ft_tolower.c \
		./srcs/ft_toupper.c \
		./srcs/ft_strlcat.c \
		./srcs/ft_calloc.c \
		./srcs/ft_split.c \
		./srcs/ft_itoa.c \
		./srcs/ft_itoa_base.c \
		./srcs/ft_strmapi.c \
		./srcs/ft_putchar.c \
		./srcs/ft_putchar_fd.c \
		./srcs/ft_putstr.c \
		./srcs/ft_putstr_fd.c \
		./srcs/ft_putendl.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_putnbr.c \
		./srcs/ft_putnbr_fd.c \
		./srcs/ft_putnbrl_fd.c \
		./srcs/ft_strtrim.c \
		./srcs/ft_lstnew_bonus.c \
		./srcs/ft_lstsize_bonus.c \
		./srcs/ft_lstdelone_bonus.c \
		./srcs/ft_putnbrul_fd.c \


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
NAME = libft.a

CC = gcc

.c.o::
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)::	$(OBJ)
			ar -rc $(NAME) $(OBJ)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

