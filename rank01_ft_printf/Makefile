# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 11:21:04 by mdesfont          #+#    #+#              #
#    Updated: 2020/09/22 10:21:52 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a

LIBFT_H = -I libft/

LIB_DIR = libft/

SRC =	./ft_display_.c \
		./ft_display_c.c \
		./ft_display_d.c \
		./ft_display_p.c \
		./ft_display_s.c \
		./ft_display_u.c \
		./ft_display_widht.c \
		./ft_display_x.c \
		./ft_initialize.c \
		./ft_parse_converts.c \
		./ft_parse_precision.c \
		./ft_parse_specifiers.c \
		./ft_parse_widht.c \
		./ft_parser.c \
		./ft_printf.c \
		./ft_send_displays.c \
		./ft_treatments.c \
		./ft_reinitialize.c \
		./ft_prec_and_width.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I./libft

CC = gcc

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			@echo LIBFT START
			make -C $(LIB_DIR)
			@echo Copying $(LIBFT_A) to root
			cp $(LIB_DIR)$(LIBFT_A) .
			mv $(LIBFT_A) $(NAME)
			ar -rc $(NAME) $(OBJ)
			ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ)
			make -C $(LIB_DIR) clean

fclean:		clean
			rm -f $(NAME)
			make -C $(LIB_DIR) fclean

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re
