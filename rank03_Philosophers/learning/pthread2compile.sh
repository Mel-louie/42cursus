#!/bin/bash

clang -Wall -Wextra -O3 -D_REENTRANT -c pthread2.c
clang -lpthread -o pthread2 pthread2.o
