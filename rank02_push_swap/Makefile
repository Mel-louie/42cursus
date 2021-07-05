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

OS_NAME = $(_VIOLET) $(shell uname -s | tr A-Z a-z) $(_END)


NAME = push_swap

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address

SRCS = src/main.c \
	src/algo_b.c \
	src/algo_s.c \
	src/algos_supersmall.c \
	src/swap_rotates.c \
	src/push_pop.c \
	src/errors.c \
	src/median.c \
	src/utils_exe.c \
	src/utils_exe2.c \
	utils/frees.c \
	utils/ft_atoi.c \
	utils/ft_isdigit.c \
	utils/ft_puts.c \
	utils/ft_splits.c \
	utils/ft_str.c \
	utils/ft_tabdup.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) 

################
#   TARGETS    #
################

all: $(NAME)
	@echo $(_GREEN)"\nDone!"$(_END)

clean:
	@echo $(_RED)"Cleaning in progress..."$(_END)
	@rm -f $(OBJS)
	@echo $(_GREEN)"Cleaning done!"$(_END)

fclean: clean
	@rm -f $(NAME)
	@echo $(_GREEN)"push_swap is delete!"$(_END)

re: fclean all

os:
	@echo $(OS_NAME)

.PHONY: all clean flcean re bonus
