#!/bin/bash

mkdir -p test/

echo "Compile ft"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=ft -o ft main.cpp

echo "Compile stl"
clang++ -Wall -Wextra -Werror -std=c++98 -DTESTED_NAMESPACE=std -o stl main.cpp

./ft >> test/ft.txt
./stl >> test/stl.txt

DIFF=$(diff test/ft.txt test/stl.txt) 
if [ "$DIFF" != "" ] 
then
    echo "The directory was modified"
fi

