#!/bin/bash

# This tests needs -DTESTED_NAMESPACE
# You must have 
#	#ifndef TESTED_NAMESPACE
#	# define TESTED_NAMESPACE
#	#endif
# in your code

#    COLORS    #
_END="\033[0m"
# Bold
_BGREEN="\033[1;32m"		# GREEN
_BWHITE="\033[1;37m"		# WHITE
_BPURPLE="\033[1;35m"		# PURPLE

rm -rf tests ft stl

mkdir -p tests/

echo "make ft"
make re
printf "${_BWHITE}------------------------------------------------\n"${_END}

echo
echo "Compile stl"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=std -o stl main.cpp
printf "${_BWHITE}[ ${_BGREEN}stl ${_BWHITE}created with success ]\n"${_END}
printf "${_BWHITE}------------------------------------------------\n"${_END}

echo

./ft >> tests/ft.txt
./stl >> tests/stl.txt

DIFF=$(diff tests/ft.txt tests/stl.txt) 
if [ "$DIFF" ]  
then
	echo "There was differences ❌"
	touch test/diff.txt
	diff tests/ft.txt tests/stl.txt > test/diff.txt
	echo "Please check tests/diff.txt to find out about them"
else
	echo "There was no differences ✅"
	echo
	make fclean
	rm -rf tests stl
	printf "${_BWHITE}[ ${_BPURPLE}stl ${_BWHITE}deleted with success ]\n"${_END}
fi

