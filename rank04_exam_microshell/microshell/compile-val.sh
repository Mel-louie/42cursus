gcc -Wall -Wextra -o microshell test.c

#test
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./microshell /bin/ls -l