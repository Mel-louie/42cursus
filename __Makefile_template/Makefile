NAME = makefile_template

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

#	DETECTOS	#
OS_NAME = $(_PURPLE) $(shell uname -s | tr A-Z a-z) $(_END)


SRCS	= main.c
#SRCS_BONUS	= bonus/srcs_bonus/main_bonus.c \

OBJ_DIR = objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
	
#OBJS_BONUS	= $(SRCS_BONUS:%.c=%.o)

# compiler
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -O3 -g3 -fsanitize=address

#LIBFT = libft.a
#INCDIR	= ./includes/
#INCDIR_BONUS = ./bonus/includes_bonus/

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR) -I $(INC_LIB_DIR)
	@printf "%-60b\r"

all : 
	@mkdir -p $(OBJ_DIR) 
	@make $(NAME) --no-print-directory

$(NAME) : $(OBJS)
#	@make -C ./libs/libft
#	@cp ./libs/libft/$(LIBFT) ./
#	@$(CC) $(OBJS)  $(LIBFT) $(CFLAGS) -I $(INCDIR) -o $(NAME) # <-- use with libft and include directory
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\n\033[1;32mCompilation of $@: Sucess\n\033[0m"

clean :
	@echo "\033[0;36mCleaning..."
#	@cd ./libs/libft; make clean
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;36m\nCleaning done\n\033[0m"

fclean :
	@echo "\033[0;36mFcleanig, remove all...\n"
#	@cd ./libs/libft; make fclean
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
#	@rm -f $(OBJS_BONUS)
	@rm -f $(NAME)
#	@rm -f $(LIBFT)
	@echo "\033[1;36m\n\nCleaning done\n\033[0m"

norminette :
	@echo "\033[1;37m"
	@norminette --version
	@echo "\nNorming...\033[0m\n"
	@echo "SRCS:"
	@norminette ./*.c
#	@echo "\nINCLUDES:"
#	@norminette ./includes/*.h
#	@echo "\nLIBFT:"
#	@norminette ./libs/libft/includes/*.h ./libs/libft/srcs/*.c

#normibonus :
#	@echo "\033[1;37m"
#	@norminette --version
#	@echo "\nNorming...\033[0m\n"
#	@echo "SRCS_BONUS:"
#	@norminette ./bonus/srcs_bonus/*.c
#	@echo "\nINCLUDES_BONUS:"
#	@norminette ./bonus/includes_bonus/*.h

#bonus : $(OBJS_BONUS)
#	@make -C ./libs/libft
#	@cp ./libs/libft/$(LIBFT) ./
#	@$(CC) $(OBJS_BONUS) $(LIBFT) $(CFLAGS) -I $(INCDIR_BONUS) -o $(NAME)
#	@echo "\n\033[1;32mCompilation OK\n\033[0m"

re : fclean all

os:
	@echo $(OS_NAME)

.PHONY: all clean fclean re
