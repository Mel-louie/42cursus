#!/bin/bash

#    COLORS    #

_BLACK="\033[30m"
_RED="\033[31m"
_GREEN="\033[32m"
_YELLOW="\033[33m"
_BLUE="\033[34m"
_VIOLET="\033[35m"
_CYAN="\033[36m"
_WHITE="\033[37m"
_END="\033[0m"
# Bold
_BBLACK="\033[1;30m"		# BLACK
_BRED="\033[1;31m"			# RED
_BGREEN="\033[1;32m"		# GREEN
_BYELLOW="\033[1;33m"		# YELLOW
_BBLUE="\033[1;34m"			# BLUE
_BPURPLE="\033[1;35m"		# PURPLE
_BCYAN="\033[1;36m"			# CYAN
_BWHITE="\033[1;37m"		# WHITE

cp *.sh ../. && cd ..
make re
printf "${_BGREEN}\n(•_•)\t( •_•)>⌐■-■\t(⌐■_■)\n${_END}"
printf "${_BYELLOW}push_swap successfully compiled\n\n${_END}"
printf "░█▀▀█ ░█─░█ ░█▀▀▀█ ░█─░█   ░█▀▀▀█ ░█──░█ ─█▀▀█ ░█▀▀█  ▀▀█▀▀ ░█▀▀▀ ░█▀▀▀█ ▀▀█▀▀ ░█▀▀▀ ░█▀▀█ \n"
printf "░█▄▄█ ░█─░█ ─▀▀▀▄▄ ░█▀▀█   ─▀▀▀▄▄ ░█░█░█ ░█▄▄█ ░█▄▄█  ─░█── ░█▀▀▀ ─▀▀▀▄▄ ─░█── ░█▀▀▀ ░█▄▄▀ \n"
printf "░█─── ─▀▄▄▀ ░█▄▄▄█ ░█─░█ ▄▄░█▄▄▄█ ░█▄▀▄█ ░█─░█ ░█───  ─░█── ░█▄▄▄ ░█▄▄▄█ ─░█── ░█▄▄▄ ░█─░█ \n"
printf "\n\t\t${_BCYAN}Welcome to my push_swap's 42 tester.${_END}\n\n"

#printf "${_BCYAN}3 error tests, should print 'Error\\\n'${_END}"
#printf "\n"
#./push_swap 1 r 5 3
#./push_swap 1 5 2 3 4 5
#./push_swap 1 2147483647 3
#printf "\n"

#printf "${_BCYAN}3 sorts tests with wc -l, should print 0\n${_END}"
#./push_swap 42 | wc -l
#./push_swap 0 1 2 3 | wc -l
#./push_swap 0 1 2 3 4 5 6 7 8 9 | wc -l
#printf "${_BCYAN}1 empty test, print nothing:\n${_END}|"
#./push_swap
#printf "|"
#printf "\n\n"

printf "${_BCYAN}\tStack interval ${_END}[${_BCYAN}1-3${_END}]\n${_END}"
printf "${_BWHITE}Random tests: wc -l:\n${_END}"
./test.sh 3
printf "${_BWHITE}\nRandom test: ./checker \$ARG:${_END} "
ARG=`ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
printf "\n\n"

printf "${_BCYAN}\tStack interval ${_END}[${_BCYAN}1-5${_END}]\n${_END}"
printf "${_BWHITE}Random tests: wc -l:\n${_END}"
./test.sh 5
printf "${_BWHITE}\nRandom test: ./checker \$ARG:${_END} "
ARG=`ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
printf "\n\n"

printf "${_BCYAN}\tStack interval ${_END}[${_BCYAN}1-100${_END}]\n${_END}"
printf "${_BWHITE}Random tests: wc -l:\n${_END}"
./test.sh 100
printf "${_BWHITE}\nRandom test: ./checker \$ARG:${_END} "
ARG=`ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
printf "\n\n"

printf "${_BCYAN}\tStack interval ${_END}[${_BCYAN}1-500${_END}]\n${_END}"
printf "${_BWHITE}Random tests: wc -l:\n${_END}"
./test.sh 500
printf "${_BWHITE}\nRandom test: ./checker \$ARG:${_END} "
ARG=`ruby -e "puts (-49..450).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
printf "\n"
rm *.sh
make fclean