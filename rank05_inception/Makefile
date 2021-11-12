
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

SRCS = ./srcs
REQ = ./srcs/requirements
IP_ADDR = "$(docker-machine env inception) | grep"

SHELL := /bin/bash

mariadb:
		docker build -t mariadb $(REQ)/mariadb

