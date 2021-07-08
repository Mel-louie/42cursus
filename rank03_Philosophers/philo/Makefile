NAME = philo

#	COLORS	#
_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_PURPLE		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
#	bold	#
B_BLACK		= "\033[1;30m"
B_RED		= "\033[1;31m"
B_GREEN		= "\033[1;32m"
B_YELLOW	= "\033[1;33m"
B_BLUE		= "\033[1;34m"
B_PURPLE	= "\033[1;35m"
B_CYAN		= "\033[1;36m"
B_WHITE		= "\033[1;37m"

#	DETECT OS	#
OS_NAME = $(_PURPLE) $(shell uname -s | tr A-Z a-z) $(_END)

SRCS_FILE		= philo.c \
					errors.c
#SRCS_FILE_BONUS = bonus.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS			= $(addprefix $(OBJS_DIR), $(SRCS_FILE:.c=.o))
#SRCS_BONUS		= $(addprefix $(SRCS_DIR_BONUS), $(SRCS_FILE_BONUS))
#OBJS_BONUS		= $(addprefix $(OBJS_DIR_BONUS), $(SRCS_FILE_BONUS:.c=.o))

SRCS_DIR		= ./srcs/
OBJS_DIR		= ./objs/
INCLUDES_DIR	= ./includes/
HEADER			= $(INCLUDES_DIR)philo.h
#SRCS_DIR_BONUS	= ./bonus/srcs_bonus/
#OBJS_DIR_BONUS	= ./bonus/objs_bonus/
#INCLUDES_DIR_BONUS = ./bonus/includes_bonus/
#INCLUDES_BONUS	= $(addprefix -I, $(INCLUDES_DIR_BONUS)
#HEADER_BONUS	= $(INCLUDES_DIR_BONUS)cub3d_bonus.h

CFLAGS			= -Wall -Wextra -Werror -O3 -g3 -fsanitize=address
CC				= clang

INCLUDES	= $(addprefix -I, $(INCLUDES_DIR))

all: launch

launch:
	@echo "[ "$(B_GREEN)"building"$(_END) "]" $(B_WHITE)"\t\t"$(NAME)$(_END)
	@$(MAKE) $(NAME)
	@echo $(_END)$(B_WHITE)"[ created with success]\t\t" $(B_GREEN)$(NAME)$(_END)

$(OBJS_DIR):
	@mkdir $@
	

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf $<
	@echo -e "\033[2K"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJS_DIR)
	@echo "[ "$(B_PURPLE)"deleted"$(_END) "]" $(B_WHITE)"\t\tobjects"$(_END)

fclean: clean
	@rm -f $(NAME)
	@echo "[ "$(B_PURPLE)"deleted"$(_END) "]" $(B_WHITE)"\t\t"$(NAME)$(_END)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s

norminette :
	@echo "\033[1;37m"
	@norminette --version
	@echo "\nNorming...\033[0m\n"
	@echo "SRCS:"
	@norminette srcs/
	@echo "\nINCLUDES:"
	@norminette includes/

os:
	@echo $(OS_NAME)

.PHONY: all clean fclean re
