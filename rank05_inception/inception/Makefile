#!make

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
#	background	#
BK_GREEN	= "\033[42m"

include srcs/.env 

NAME		=	inception

COMPOSE		=	cd srcs && docker-compose -p $(NAME)

RM			=	rm -rf

MAKE_DIR	=	mkdir -p

CHMOD		=	chmod -R 777

all: up

build:
	$(COMPOSE) build

up:	stop
	@printf $(B_CYAN)"Launching docker-compose\n\n"$(_END)
	@$(MAKE_DIR) $(WP_HOST_VOLUME_PATH)
	@$(MAKE_DIR) $(MYSQL_HOST_VOLUME_PATH)
	@$(CHMOD) $(WP_HOST_VOLUME_PATH)
	@$(CHMOD) $(MYSQL_HOST_VOLUME_PATH)
	@$(COMPOSE) up -d --build
	@$(CHMOD) $(WP_HOST_VOLUME_PATH)
	@$(CHMOD) $(MYSQL_HOST_VOLUME_PATH)

stop:
	@printf $(B_RED)"Stoping containers\n"$(_END)
	@$(COMPOSE) stop

start:
	@printf $(B_GREEN)"Starting containers\n"$(_END)
	@$(COMPOSE) start

down: stop
	@printf $(B_RED)"docker-compose down -v\n"$(_END)
	@$(COMPOSE) down -v

re:		down all

prune:	down
	@printf $(B_RED)"Docker prune and rm -rf persistents directories\n"$(_END)
	@docker system prune --volumes --force --all
	@sudo $(RM) $(WP_HOST_VOLUME_PATH)
	@sudo $(RM) $(MYSQL_HOST_VOLUME_PATH)

.PHONY: all build up stop down re prune start