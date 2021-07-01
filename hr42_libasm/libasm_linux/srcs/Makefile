# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 14:00:30 by mdesfont          #+#    #+#              #
#    Updated: 2020/08/19 11:05:24 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libasm.a

SRC =		./ft_strcmp.s \
			./ft_strcpy.s \
			./ft_strlen.s \
			./ft_read.s \
			./ft_strdup.s \
			./ft_write.s

OBJ =		$(SRC:%.s=%.o)

%.o: %.s
	@nasm -f elf64 $<

all:		$(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)


clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
