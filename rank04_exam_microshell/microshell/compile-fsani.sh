gcc -Wall -Wextra -g3 -fsanitize=address -o microshell test.c

#test
./microshell /bin/ls -l