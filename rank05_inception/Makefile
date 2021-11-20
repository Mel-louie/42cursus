
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

#@printf $(BK_GREEN)"                "$(_END)

COMPOSE_FILE=./srcs/docker-compose.yml

all: run

run:
	@printf $(B_CYAN)"Creating folders for volumes...\n"$(_END)
	@sudo mkdir -p /home/mdesfont/data/database
	@sudo mkdir -p /home/mdesfont/data/wordpress
	@printf "|"$(BK_GREEN)"                "$(_END)"|\n"
	@docker-compose -f $(COMPOSE_FILE) up --build

up:
	@printf $(B_CYAN)"Creating folders for volumes...\n"$(_END)
	@sudo mkdir -p /home/mdesfont/data/database
	@sudo mkdir -p /home/mdesfont/data/wordpress
	@printf "|"$(BK_GREEN)"                "$(_END)"|\n"
	@docker-compose -f $(COMPOSE_FILE) up -d --build

debug:
	@printf $(B_CYAN)"Creating folders for volumes...\n"$(_END)
	@sudo mkdir -p /home/mdesfont/data/database
	@sudo mkdir -p /home/mdesfont/data/wordpress
	@printf "|"$(BK_GREEN)"                "$(_END)"|\n"
	@docker-compose -f $(COMPOSE_FILE) --verbose up

list:
	@printf $(B_CYAN)"Listing all containers:\n"$(_END)
	 docker ps -a

list_volumes:
	@printf $(B_CYAN)"Listing all volumes:\n"$(_END)
	 docker volume ls

clean:
	@printf $(B_RED)"Stopping containers...\n"$(_END)
	@docker-copose -f $(COMPOSE_FILE) down
	@-docker stop `docker ps -qa`
	@-docker rm `docker ps -qa`
	@printf $(B_RED)"Deleting images...\n"$(_END)
	@-docker rmi -i `docker images -qa`
	@printf "$(B_RED)Deleting all volumes ... $(RESET)"
	@-docker volume rm `docker volume ls -q`
	@printf "$(B_RED)Deleting all network ... $(RESET)"
	@-docker network rm `docker network ls -q`
	@printf "$(B_RED)Deleting all data ... $(RESET)"
	@sudo rm -rf /home/mdesfont/data/wordpress
	@sudo rm -rf /home/mdesfont/data/database
	@printf "$(B_RED)Deleting all $(RESET)"

.PHONY: run up debug list list_volumes clean