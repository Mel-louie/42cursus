# *******************************    POST-IT    ****************************** #
#                                                                              #
#			## $@ 	Le nom de la cible										   #
#			## $< 	Le nom de la première dépendance						   #
#			## $^ 	La liste des dépendances								   #
#			## $? 	La liste des dépendances plus récentes que la cible		   #
#			## $* 	Le nom du fichier sans suffixe							   #
#                                                                              #
# **************************************************************************** #

#!make
include srcs/.env 

NAME		=	inception

COMPOSE		=	cd srcs && docker-compose -p $(NAME)

RM			=	rm -rf

MAKE_DIR	=	mkdir -p

CHMOD		=	chmod -R 777

all: .up

build:
	$(COMPOSE) build

.up:	clean
	$(MAKE_DIR) $(WP_HOST_VOLUME_PATH)
	$(MAKE_DIR) $(MYSQL_HOST_VOLUME_PATH)
	$(CHMOD) $(WP_HOST_VOLUME_PATH)
	$(CHMOD) $(MYSQL_HOST_VOLUME_PATH)
	docker network create inception_network
	$(COMPOSE) up -d --build
	$(CHMOD) $(WP_HOST_VOLUME_PATH)
	$(CHMOD) $(MYSQL_HOST_VOLUME_PATH)

clean:
	if docker network rm inception_network; then echo "No network to remove"; fi
	$(COMPOSE) stop

fclean:
	$(COMPOSE) down -v

re:		fclean all

prune:	fclean
	docker system prune --volumes --force --all
	if $(RM) $(WP_HOST_VOLUME_PATH); then echo "No data folder to remove"; fi
	if $(RM) $(MYSQL_HOST_VOLUME_PATH); then echo "No data folder to remove"; fi

.PHONY: all build .up clean fclean re prune