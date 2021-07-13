#!/bin/bash

clang -Wall -Wextra -Werror -O3 -D_REENTRANT -c pthread1.c
clang -lpthread -o pthread1 pthread1.o
