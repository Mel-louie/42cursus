# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 15:51:10 by mdesfont          #+#    #+#              #
#    Updated: 2020/07/31 09:37:28 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_u_itoa.c \
	ft_itoa_base.c \
	ft_strcpy.c \
	ft_strjoinfree.c \
	ft_strncpy.c \
	get_next_line.c \
	ft_strcmp.c \
	ft_len_tab.c \
	ft_free_tab.c \
	ft_strisalpha.c

SRC_PATH = ./src/
OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))


CFLAGS = -Werror -Wall -Wextra


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)

nameclean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean nameclean

.SILENT: