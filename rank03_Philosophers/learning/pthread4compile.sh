#!/bin/bash

clang -Wall -Wextra -O3 -D_REENTRANT -c pthread4.c
clang -lpthread -o pthread4 pthread4.o
