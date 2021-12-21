#!/bin/bash

# This test needs -DTESTED_NAMESPACE
# You must have 
#	#ifndef TESTED_NAMESPACE
#	# define TESTED_NAMESPACE
#	#endif
# in your code

mkdir -p test/

echo "Compile ft"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=ft -o ft main.cpp

echo "Compile stl"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=std -o stl main.cpp

./ft >> test/ft.txt
./stl >> test/stl.txt

DIFF=$(diff test/ft.txt test/stl.txt) 
if [ "$DIFF" ]  
then
	echo "There was differences ❌"
	diff test/ft.txt test/stl.txt > test/diff.txt
else
	echo "There was no differences ✅"
	rm -rf test ft stl
fi

