gcc -Wall -Wextra -g3 -fsanitize=address -o microshell microshell.c

#test
./microshell /bin/ls -l