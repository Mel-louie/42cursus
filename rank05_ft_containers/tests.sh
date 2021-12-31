#!/bin/bash

# This tests needs -DTESTED_NAMESPACE when compil
# You must have 
#	#ifndef TESTED_NAMESPACE
#	# define TESTED_NAMESPACE
#	#endif
# in your code

#    COLORS    #
_END="\033[0m"
# Bold
_BGREEN="\033[1;32m"		# GREEN
_BRED="\033[1;31m"			# RED
_BWHITE="\033[1;37m"		# WHITE
_BPURPLE="\033[1;35m"		# PURPLE

rm -rf tests ft stl

mkdir -p tests/

printf "${_BWHITE}[ Compilation and launching... ]\n${_END}"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=std -g3 -fsanitize=address -o stl main.cpp
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=ft -g3 -fsanitize=address -o ft main.cpp

./ft >> tests/ft.txt
./stl >> tests/stl.txt

DIFF=$(diff tests/ft.txt tests/stl.txt) 
if [ "$DIFF" ]  
then
	echo "There was differences ❌"
	diff tests/ft.txt tests/stl.txt > tests/diff.txt
	echo "Please check tests/diff.txt to find out about them"
else
	printf "\n${_BWHITE}Comparaison tests OK ✅${_END}\n"
	printf "There was no difference between stl_containers and ft_containers\n\n"
	printf "${_BWHITE}------------------------------------------------\n${_END}"
	rm -rf tests stl ft
fi

echo
cd stressTests
printf "${_BWHITE}[ Launching stress tests... ]\n${_END}"
printf "${_BWHITE}-----------------------------\n${_END}"
sh stress_tests.sh
