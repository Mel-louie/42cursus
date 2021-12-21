#!/bin/bash

# This tests needs -DTESTED_NAMESPACE
# You must have 
#	#ifndef TESTED_NAMESPACE
#	# define TESTED_NAMESPACE
#	#endif
# in your code

rm -rf tests ft stl

mkdir -p tests/

echo "Compile ft"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=ft -o ft main.cpp

echo "Compile stl"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=std -o stl main.cpp

./ft >> tests/ft.txt
./stl >> tests/stl.txt

DIFF=$(diff tests/ft.txt tests/stl.txt) 
if [ "$DIFF" ]  
then
	echo "There was differences ❌"
	diff tests/ft.txt tests/stl.txt > test/diff.txt
	echo "Please check tests/diff.txt to find out about them"
else
	echo "There was no differences ✅"
	rm -rf tests ft stl
fi

