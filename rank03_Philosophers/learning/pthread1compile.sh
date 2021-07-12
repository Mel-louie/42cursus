#!/bin/bash

clang -Wall -Wextra -Werror -O3 -D_REENTRANT -c pthread.c
clang -lpthread -o pthread pthread.o
