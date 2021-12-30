#!/bin/bash

echo "Compile..."
echo "clang++ -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address stress_tests.cpp"
clang++ -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address -o stressTests stress_tests.cpp
echo
echo "Run:"
./stressTests
rm stressTests