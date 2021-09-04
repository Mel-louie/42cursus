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
					parsing.c \
					thread.c \
					utils_thread.c \
					utils.c

SRCS_DIR		= ./srcs/
OBJS_DIR		= ./objs/
INCLUDES_DIR	= ./includes/

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS			= $(addprefix $(OBJS_DIR), $(SRCS_FILE:.c=.o))
INCLUDES		= $(addprefix -I, $(INCLUDES_DIR))
HEADER			= $(INCLUDES_DIR)philo.h

CFLAGS			= -Wall -Wextra -Werror -O3 -g3 -fsanitize=address
CC				= clang


all: launch

launch:
	@echo "[ "$(B_GREEN)"building"$(_END) "]" $(B_WHITE)"\t\t"$(NAME)$(_END)
	@$(MAKE) $(NAME)
	@echo $(_END)$(B_WHITE)"[ "$(B_GREEN)$(NAME)$(_END)$(B_WHITE)" created with success ]\t"

$(OBJS_DIR):
	@mkdir $@
	

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) -D_REENTRANT $(INCLUDES) -c $< -o $@
	@printf $<
	@printf "\r"

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
