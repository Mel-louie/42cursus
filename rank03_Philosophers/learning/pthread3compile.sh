#!/bin/bash

clang -Wall -Wextra -Werror -O3 -D_REENTRANT -c pthread3.c
clang -lpthread -o pthread3 pthread3.o
