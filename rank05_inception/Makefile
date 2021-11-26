
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

COMPOSE_FILE=./srcs/docker-compose.yml

all:
	@printf $(B_CYAN)"Launch docker-compose...\n\n"$(_END)
	@sudo mkdir -p /home/mdesfont/data/wordpress
	@sudo mkdir -p /home/mdesfont/data/mariadb
	@docker-compose -f $(COMPOSE_FILE) up --build

list:
	@printf $(B_CYAN)"Listing all containers:\n"$(_END)
	 docker ps -a

list_volumes:
	@printf $(B_CYAN)"Listing all volumes:\n"$(_END)
	 docker volume ls

clean:
	@printf $(B_RED)"Stopping containers, deleting images, volumes and network...\n"$(_END)
	@docker-compose -f $(COMPOSE_FILE) down
	@sudo docker rmi -f $(sudo docker images -qa)
	@sudo docker rm -f $(sudo docker ps -qa)
	@sudo docker rm -f $(sudo docker ps -ls)
	@sudo docker volume rm $(sudo docker volume ls -q)
	@sudo docker system prune -a --volume
	@sudo docker system prune -a --force
	@sudo rm -Rf ../../data/mariadb
	@sudo rm -Rf ../../data/wordpress

.PHONY: all list list_volumes clean