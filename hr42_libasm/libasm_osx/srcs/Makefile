# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 20:05:55 by mdesfont          #+#    #+#              #
#    Updated: 2020/08/19 11:05:21 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		./ft_write.s \
			./ft_read.s \
			./ft_strlen.s \
			./ft_strcpy.s \
			./ft_strcmp.s \
			./ft_strdup.s

OBJ =		$(SRC:%.s=%.o)

NAME =		libasm.a

%.o: %.s
	@nasm -f macho64 $<

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re